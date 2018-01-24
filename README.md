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
$ ./configure
$ sudo make install
```
Couple problems refer to old versions of programs which are used during compilation. It's solved with simlinks on current versions of ones.

To compile DEB package with Debian patches do it:
```Shell
$ cd ya_ctorrent
$ dpkg-buildpackage --build=any
$ dpkg-deb -b debian/ctorrent/ my_ctorrent.deb
```
To install the package:
```Shell
$ sudo dpkg -i --no-debsig my_ctorrent.deb
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
