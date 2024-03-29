## Why?
Genuine ctorrent programm doesn't support environment variables at all. As result, we cann't adapt it to our circumstances. The patch implements support of HTTP_PROXY environment variable.
___
It's required some additional packages (and their dependencies) to be installed: dpkg-dev, quilt, debhelper.

A source code was taken from Debian repository:
```Shell
$ mkdir -p /tmp/ctorrent
$ cd /tmp/ctorrent
$ apt-get source ctorrent
```
### HowTo
Get .diff and .patch files
```Shell
$ git clone <the repository URL>
$ cp -iv ya_ctorrent/{ctorrent.1.patch,http-proxy-v2.diff} .
```
and then:
```Shell
$ cd ctorrent-1.3.4.dnh3.3.2
$ patch -p1 < ../ctorrent.1.patch
$ quilt import ../http-proxy-v2.diff
$ quilt push
```

To compile DEB package with Debian patches do it:
```Shell
$ dpkg-buildpackage --no-sign -d
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
