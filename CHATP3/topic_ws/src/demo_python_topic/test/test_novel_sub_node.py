import ast
import importlib
from pathlib import Path

import rclpy


def _setup_keyword_value(name):
    tree = ast.parse(Path("setup.py").read_text(encoding="utf-8"))
    for node in ast.walk(tree):
        if isinstance(node, ast.Call) and getattr(node.func, "id", None) == "setup":
            for keyword in node.keywords:
                if keyword.arg == name:
                    return ast.literal_eval(keyword.value)
    raise AssertionError(f"setup.py is missing {name!r}")


def test_setup_declares_espeakng_dependency():
    install_requires = _setup_keyword_value("install_requires")
    assert "espeakng" in install_requires


def test_local_espeakng_wrapper_exports_speaker():
    module = importlib.import_module("demo_python_topic._espeakng")
    assert module.Speaker is not None


def test_novel_sub_node_can_be_created(tmp_path, monkeypatch):
    module = importlib.import_module("demo_python_topic.novel_sub_node")
    monkeypatch.setenv("ROS_LOG_DIR", str(tmp_path))

    rclpy.init()
    try:
        node = module.NovelSubNode("novel_sub")
        try:
            assert node.novel_queue_.qsize() == 0
        finally:
            node.destroy_node()
    finally:
        rclpy.shutdown()
