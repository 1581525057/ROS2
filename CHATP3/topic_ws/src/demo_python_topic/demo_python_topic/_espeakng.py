from importlib import import_module


try:
    _espeakng = import_module("espeakng")
except ModuleNotFoundError as exc:
    raise ModuleNotFoundError(
        "espeakng is not installed in the current Python environment."
    ) from exc


Speaker = _espeakng.Speaker

__all__ = ["Speaker"]
