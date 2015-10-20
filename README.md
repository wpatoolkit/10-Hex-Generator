# Hex Generator
This is a small program written in C++ that will output hex digits while skipping over certain combinations it believes to be invalid.

Only combinations which meet these criteria will be printed:<br>
&nbsp;&bull; does not contain 9+ numbers<br>
&nbsp;&bull; does not contain 9+ letters<br>
&nbsp;&bull; does not begin with 00, 11, 22, 33, 55, 66, 77, aa, bb, cc, dd, ee, ff<br>
&nbsp;&bull; no 3 characters in a row can be sequential<br>
&nbsp;&bull; no 3 characters in a row can be identical (except 2,3,4 or 3,4,5)<br>
&nbsp;&bull; each character cannot appear more than 3 times<br>
&nbsp;&bull; characters 1 and 3, and 2 and 4 are not identical<br>
&nbsp;&bull; characters 3 and 5, and 4 and 6 are not identical<br>
&nbsp;&bull; characters 1 and 3 and 4 are not identical<br>
&nbsp;&bull; characters 2 and 3 and 10 are not identical<br>
&nbsp;&bull; when characters 1 and 3 are equal, character 4 is not +1 to character 2<br>

To compile on Windows (requires the <a href="http://www.microsoft.com/en-us/download/details.aspx?id=8279">Windows 7 SDK</a>):<br>
`cl /EHsc 10hex.cpp`

To compile on Linux:<br>
`g++ 10hex.cpp -o10hex`

##Example usage:
`10hex | oclHashcat64 -m 2500 CAP.hccap`<br>
pipes its output into <a href="http://hashcat.net/oclhashcat/">oclHashcat</a> (AMD)

`10hex | cudaHashcat64 -m 2500 CAP.hccap`<br>
pipes its output into <a href="http://hashcat.net/oclhashcat/">cudaHashcat</a> (NVIDIA)

`10hex | aircrack-ng -w - CAP.cap -e SSID`<br>
pipes its output into <a href="http://www.aircrack-ng.org/">aircrack-ng</a>

`./10hex | pyrit -r CAP.cap -i- attack_passthrough`<br>
pipes its output into <a href="https://code.google.com/p/pyrit/">pyrit</a>

## Parameters
You can optionally specify any of these parameters to further refine your output.

`-evenonly`<br>
Will only output even numbers<br>

`-oddonly`<br>
Will only output odd numbers<br>

`-random`<br>
Will randomize its output while still maintaining rules<br>

`-lower`<br>
Forces all output to be lowercase<br>

`-upper`<br>
Forces all output to be uppercase<br>

`-len8`<br>
Only outputs 8-length hex digits<br>

`-len9`<br>
Only outputs 9-length hex digits<br>

`-no0`<br>
Ignores all combinations which have a 0 in them<br>
 
`-no1`<br>
Ignores all combinations which have a 1 in them<br>
 
`-no01`<br>
Ignores all combinations which have a 0 or a 1 in them<br>

`-Xuniques`<br>
Only outputs combinations which have X unique characters in them (typically 6, 7, 8 or 9)<br>

`-Xminuniques`<br>
Only outputs combinations which have a minimum of X unique characters in them.<br>

`-startswithX`<br>
Only outputs combinations which start with X (can be 0-F).<br>

`-start X`<br>
Start on combination X (where X is a number between 0 and 799711022334)<br>

`-stop X`<br>
Stop on combination X (where X is a number between 1 and 799711022334)<br>
