import socket
import sys
import ssl

def main():

    address = 'www.uvic.ca'
    protocol = 80


    try:
        s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
        if protocol == 443:
            context = ssl.create_default_context()
            s = context.wrap_socket(s, server_hostname=address)
            s.connect((address, protocol))
            http2 = s.selected_alpn_protocol()
            if http2 == 'h2':
                supports_http2 = 'yes'
        else:
            s.connect((address, protocol))
    except socket.error:
        print('Socket Creation Failed')
        sys.exit()

if

    