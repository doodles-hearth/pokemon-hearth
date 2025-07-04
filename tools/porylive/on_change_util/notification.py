import socket
from .logger import Logger

class NotificationManager:
    """Handles socket communication with porylive.lua"""

    def __init__(self, logger: Logger, host: str = 'localhost', port: int = 1370):
        self.logger = logger
        self.host = host
        self.port = port

    def send_notification(self, message: str):
        """Send a reload notification to porylive.lua via socket"""
        try:
            # Try to connect to the Lua script on localhost:1370
            sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
            sock.settimeout(2.0)  # 2 second timeout
            sock.connect((self.host, self.port))
            sock.send(message.encode('utf-8'))
            sock.close()
            self.logger.log_message(f"Sent notification to porylive.lua: {message}")
        except socket.timeout:
            self.logger.log_message(f"Failed to send notification to porylive.lua: {message}",
                        "Timeout connecting to porylive.lua - make sure mGBA is running with porylive.lua loaded")
        except ConnectionRefusedError:
            self.logger.log_message(f"Failed to send notification to porylive.lua: {message}",
                        "Connection refused - see tools/porylive/README.md for setup instructions")
        except Exception as e:
            self.logger.log_message(f"Failed to send notification to porylive.lua: {e}")

    def send_processing(self):
        """Send PROCESSING notification"""
        self.send_notification("PROCESSING")

    def send_reload(self):
        """Send RELOAD notification"""
        self.send_notification("RELOAD")
