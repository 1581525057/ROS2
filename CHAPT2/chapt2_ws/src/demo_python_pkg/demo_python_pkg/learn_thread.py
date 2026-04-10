import threading
import requests


class Download:
    def download(self, url, callback_world_count):
        print(f"线程：{threading.get_ident()} 开始下载：{url}")
        response = requests.get(url, timeout=5)
        response.raise_for_status()
        response.encoding = 'utf-8'
        callback_world_count(url, response.text)

    def start_download(self, url, callback_world_count):
        thread = threading.Thread(
            target=self.download, args=(url, callback_world_count)
        )
        thread.start()


def world_count(url, result):
    print(f"下载完成：{url}，内容长度：{len(result)}，前 5 个字符：{result[:5]}")


def main():
    download = Download()
    download.start_download("http://127.0.0.1:8000/novel1.txt", world_count)
    download.start_download("http://127.0.0.1:8000/novel2.txt", world_count)
    download.start_download("http://127.0.0.1:8000/novel3.txt", world_count)

