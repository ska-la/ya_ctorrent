## Why?
Genuine ctorrent programm doesn't support environment variables at all. As result, we cann't adapt it to our circumstances. The patch implements support of HTTP_PROXY environment variable.
___
A source code was taken from Debian repository:
```Shell
$ apt-get source ctorrent
```
### HowTo
Clone it and compile:
```Shell
$ git clone ...
$ cd ya_ctorrent
$ autoreconf -isvf
$ ./configure
$ sudo make install
```

To compile DEB package with Debian patches do it:
```Shell
$ cd ya_ctorrent
$ dpkg-buildpackage --no-sign
```
To install the package:
```Shell
$ sudo dpkg -i --no-debsig ../ctorrent_1.3.4.xxx.deb
```
To remove the package:
```Shell
$ sudo dpkg -r ctorrent
```
### Example
When proxy server provides 3128 port (by default), use:
```Shell
$ http_proxy=proxy2.example.com ctorrent John_Smith.torrent
```
else:
```Shell
$ http_proxy=proxy1.example.com:12345 ctorrent J.Smith.torrent
```
___
#### Good Luck!
