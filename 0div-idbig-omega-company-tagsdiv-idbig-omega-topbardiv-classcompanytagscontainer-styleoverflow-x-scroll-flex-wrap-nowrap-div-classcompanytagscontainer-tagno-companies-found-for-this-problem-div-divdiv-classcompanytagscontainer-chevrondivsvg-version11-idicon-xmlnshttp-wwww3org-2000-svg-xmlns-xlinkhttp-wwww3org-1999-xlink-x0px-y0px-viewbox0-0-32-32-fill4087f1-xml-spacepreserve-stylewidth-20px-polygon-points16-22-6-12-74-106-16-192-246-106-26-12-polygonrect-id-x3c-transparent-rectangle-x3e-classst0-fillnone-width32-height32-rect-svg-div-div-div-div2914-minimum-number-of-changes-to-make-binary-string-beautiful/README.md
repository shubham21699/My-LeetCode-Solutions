<h2><a href="https://leetcode.com/problems/minimum-number-of-changes-to-make-binary-string-beautiful/"><div id="big-omega-company-tags"><div id="big-omega-topbar"><div class="companyTagsContainer" style="overflow-x: scroll; flex-wrap: nowrap;"><div class="companyTagsContainer--tag">No companies found for this problem</div></div><div class="companyTagsContainer--chevron"><div><svg version="1.1" id="icon" xmlns="http://www.w3.org/2000/svg" xmlns:xlink="http://www.w3.org/1999/xlink" x="0px" y="0px" viewBox="0 0 32 32" fill="#4087F1" xml:space="preserve" style="width: 20px;"><polygon points="16,22 6,12 7.4,10.6 16,19.2 24.6,10.6 26,12 "></polygon><rect id="_x3C_Transparent_Rectangle_x3E_" class="st0" fill="none" width="32" height="32"></rect></svg></div></div></div></div>2914. Minimum Number of Changes to Make Binary String Beautiful</a></h2><h3>Medium</h3><hr><div><p>You are given a <strong>0-indexed</strong> binary string <code>s</code> having an even length.</p>

<p>A string is <strong>beautiful</strong> if it's possible to partition it into one or more substrings such that:</p>

<ul>
	<li>Each substring has an <strong>even length</strong>.</li>
	<li>Each substring contains <strong>only</strong> <code>1</code>'s or <strong>only</strong> <code>0</code>'s.</li>
</ul>

<p>You can change any character in <code>s</code> to <code>0</code> or <code>1</code>.</p>

<p>Return <em>the <strong>minimum</strong> number of changes required to make the string </em><code>s</code> <em>beautiful</em>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre><strong>Input:</strong> s = "1001"
<strong>Output:</strong> 2
<strong>Explanation:</strong> We change s[1] to 1 and s[3] to 0 to get string "1100".
It can be seen that the string "1100" is beautiful because we can partition it into "11|00".
It can be proven that 2 is the minimum number of changes needed to make the string beautiful.
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre><strong>Input:</strong> s = "10"
<strong>Output:</strong> 1
<strong>Explanation:</strong> We change s[1] to 1 to get string "11".
It can be seen that the string "11" is beautiful because we can partition it into "11".
It can be proven that 1 is the minimum number of changes needed to make the string beautiful.
</pre>

<p><strong class="example">Example 3:</strong></p>

<pre><strong>Input:</strong> s = "0000"
<strong>Output:</strong> 0
<strong>Explanation:</strong> We don't need to make any changes as the string "0000" is beautiful already.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>2 &lt;= s.length &lt;= 10<sup>5</sup></code></li>
	<li><code>s</code> has an even length.</li>
	<li><code>s[i]</code> is either <code>'0'</code> or <code>'1'</code>.</li>
</ul>
</div>