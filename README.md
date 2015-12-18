# 10 Hex Keyspace Reducer
<b>What's new</b><br>
Version 1.5 now includes a pattern analyzer (10hex.html) than can perform in-depth analytics of known valids, faster piping speed and more keyspace reducing rules.
<br><br>
<b>What is it?</b><br>
This is a small program written in C++ that will output all possible combinations of 10 hex digits while skipping over certain combinations it believes to be invalid.
<br><br>
Only combinations which meet these criteria will be printed:<br>
&nbsp;&bull; must contain 6-9 unique characters (can be expanded to 5-9 with the `-5minuniques` option)<br>
&nbsp;&bull; must contain 4-8 numbers<br>
&nbsp;&bull; must contain 2-6 letters<br>
&nbsp;&bull; no 3 consecutive chars are sequential or reverse sequential (<10% occurrence rate)<br>
&nbsp;&bull; no 3 consecutive chars are identical (<3% occurrence rate)<br>
&nbsp;&bull; each character cannot appear more than 3 times (<5% occurrence rate)<br>
&nbsp;&bull; the total difference between all chars cannot be less than 19 or greater than 79<br>

<b>Character 2 Traits</b><br>
&nbsp;&bull; c2 is not equal to c1 (eliminates 68,719,476,736 combinations) (<1% occurrence rate)<br>
&nbsp;&bull; c2 is not -15 to c1 (eliminates 4,294,967,296 combinations)<br>
&nbsp;&bull; c2 is not -14 to c1 (eliminates 8,589,934,592 combinations)<br>

<b>Character 3 Traits</b><br>
&nbsp;&bull; c2 and c3 and c10 are not identical<br>
&nbsp;&bull; c3 is not -15 to c2 (eliminates 4,294,967,296 combinations)<br>
&nbsp;&bull; c3 is not -13 to c2 (eliminates 12,884,901,888 combinations)<br>
&nbsp;&bull; c3 is not +15 to c2 (eliminates 4,294,967,296 combinations)<br>
&nbsp;&bull; c3 is not -15 to c1 (eliminates 4,294,967,296 combinations)<br>
&nbsp;&bull; c3 is not -14 to c1 (eliminates 8,589,934,592 combinations)<br>
&nbsp;&bull; c3 is not -13 to c1 (eliminates 12,884,901,888 combinations)<br>
&nbsp;&bull; c3 is not +13 to c1 (eliminates 12,884,901,888 combinations)<br>

<b>Character 4 Traits</b><br>
&nbsp;&bull; when c1 equals c3, c4 is not equal to c2 (eliminates 4,294,967,296 combinations)<br>
&nbsp;&bull; when c1 equals c3, c4 is not +1 to c2 (eliminates 4,026,531,840 combinations)<br>
&nbsp;&bull; when c1 equals c3, c4 is not equal to c3 (eliminates 4,294,967,296 combinations)<br>
&nbsp;&bull; when c3 equals c5, c4 is not equal to c6<br>
&nbsp;&bull; c4 is not -15 to c3 (eliminates 4,294,967,296 combinations)<br>
&nbsp;&bull; c4 is not -14 to c3 (eliminates 8,589,934,592 combinations)<br>
&nbsp;&bull; c4 is not +14 to c3 (eliminates 8,589,934,592 combinations)<br>
&nbsp;&bull; c4 is not +15 to c3 (eliminates 4,294,967,296 combinations)<br>
&nbsp;&bull; c4 is not +13 to c2 (eliminates 12,884,901,888 combinations)<br>
&nbsp;&bull; c4 is not +14 to c2 (eliminates 8,589,934,592 combinations)<br>
&nbsp;&bull; c4 is not +15 to c2 (eliminates 4,294,967,296 combinations)<br>
&nbsp;&bull; c4 is not -15 to c1 (eliminates 4,294,967,296 combinations)<br>
&nbsp;&bull; c4 is not -14 to c1 (eliminates 8,589,934,592 combinations)<br>
&nbsp;&bull; c4 is not -13 to c1 (eliminates 12,884,901,888 combinations)<br>
&nbsp;&bull; c4 is not +14 to c1 (eliminates 8,589,934,592 combinations)<br>
&nbsp;&bull; c4 is not +15 to c1 (eliminates 4,294,967,296 combinations)<br>

<b>Character 5 Traits</b><br>
&nbsp;&bull; c5 is not +15 to c4<br>
&nbsp;&bull; c5 is not -15 to c3<br>
&nbsp;&bull; c5 is not +14 to c3<br>
&nbsp;&bull; c5 is not +15 to c3<br>
&nbsp;&bull; c5 is not -15 to c2<br>
&nbsp;&bull; c5 is not +13 to c2<br>
&nbsp;&bull; c5 is not +14 to c2<br>
&nbsp;&bull; c5 is not +15 to c2<br>
&nbsp;&bull; c5 is not -13 to c1<br>
&nbsp;&bull; c5 is not +13 to c1<br>
&nbsp;&bull; c5 is not +14 to c1<br>

<b>Character 6 Traits</b><br>
&nbsp;&bull; when c3 equals c5, c4 does not equal c6<br>
&nbsp;&bull; c6 is not -15 to c5<br>
&nbsp;&bull; c6 is not -14 to c5<br>
&nbsp;&bull; c6 is not -13 to c5<br>
&nbsp;&bull; c6 is not +14 to c5<br>
&nbsp;&bull; c6 is not +15 to c5<br>
&nbsp;&bull; c6 is not -15 to c4<br>
&nbsp;&bull; c6 is not -14 to c4<br>
&nbsp;&bull; c6 is not -13 to c4<br>
&nbsp;&bull; c6 is not +14 to c4<br>
&nbsp;&bull; c6 is not -15 to c3<br>
&nbsp;&bull; c6 is not -14 to c3<br>
&nbsp;&bull; c6 is not -13 to c3<br>
&nbsp;&bull; c6 is not +15 to c3<br>
&nbsp;&bull; c6 is not -14 to c2<br>
&nbsp;&bull; c6 is not +13 to c2<br>
&nbsp;&bull; c6 is not +14 to c2<br>
&nbsp;&bull; c6 is not -15 to c1<br>
&nbsp;&bull; c6 is not -14 to c1<br>

Without keyspace reducing rules there are 1,099,511,627,776 (16^10) combinations in the keyspace (~13,194 GB in wordlist form).
<br><br>
Applying these rules brings it down to 564,561,702,612 combinations or 51.3% of the original keyspace (~6,775 GB in wordlist form).
<br><br>
Using the `-risky` parameter will bring it down even further to 367,647,332,933 or 33.4% of the keyspace (~4,412 GB in wordlist form) but with a slightly decreased chance of success.

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

`-risky`<br>
Offers significant time savings but with a higher risk of failure by using tighter differentials (the total distance between characters).<br> 

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
