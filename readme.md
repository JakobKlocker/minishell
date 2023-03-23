<h1>Minishell</h1>
<p>Minishell is a simple shell program developed as a project for the 42 school's curriculum. The aim of this project is to implement a basic shell program capable of executing basic commands and managing environment variables.</p>
<h2>Features</h2>
<p>Minishell supports the following features:</p>
<ul>
<li>Execution of basic commands (<strong>ls, echo, pwd, cat, etc.</strong>)</li>
<li>Basic redirections (e.g., <strong>&gt;, &lt;, &gt;&gt;</strong>)</li>
<li>Environment variables management (<strong>export, unset</strong>)</li>
<li>Basic signal handling (<strong>ctrl+C, ctrl+D</strong>)</li>
<li>Pipes ( <strong>|</strong> )</li>
</ul>
<h2>Getting Started</h2>
<p>To get started with Minishell, follow these steps:</p>
<ol>
<li>Clone this repository to your local machine:</li>
</ol>
<pre><code class="language-bash">git clone https://github.com/jakobklocker/minishell_42.git
</code></pre>
<ol start="2">
<li>Navigate to the project directory:</li>
</ol>
<pre><code class="language-bash">cd minishell_42
</code></pre>
<ol start="3">
<li>Build the program:</li>
</ol>
<pre><code class="language-bash">make
</code></pre>
<ol start="4">
<li>Run the program:</li>
</ol>
<pre><code class="language-bash">./minishell
</code></pre>
<h2>Usage</h2>
<p>Once you have launched the program, you can enter basic commands as you would in a regular shell. Minishell supports a number of built-in commands, such as echo, cd, pwd, export, unset, and env. To execute a command, simply enter it at the prompt and press enter:</p>
<pre><code class="language-bash">$ echo Hello, World!
Hello, World!
</code></pre>
<p>Minishell also supports basic redirections. For example, to redirect the output of a command to a file, use the &gt; operator:</p>
<pre><code class="language-bash">$ echo Hello &gt; hello.txt
</code></pre>
<p>This will create a new file called hello.txt and write the output of the echo command to it.</p>
<p>Pipes work as they do in the offical shell, creating one child process each pipe</p>
<pre><code class="language-bash">$ ls | grep mini
</code></pre>
