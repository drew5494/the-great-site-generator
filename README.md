<h1>The Great Site Generator</h1>
<p>Actually jsut another site generator that allows you to generate static sites based off of text data.</p>

<h2>Tool Setup</h2>
<p>This builds TGSG with cmake so you can run it using the <code>./tgsg</code>
command.</p>
<ul>
    <li>Clone the repository</li>
    <li><code>cd</code> into the folder</li>
    <li>run <code>cmake .</code> to generate a Makefile</li>
    <li>run <code>make</code></li>
</ul>

<h2>Features</h2>

<h3>Input</h3>
<p>The <code>-i or --input</code> flag means the input path. This will look for all texts files 
    within the folder. You can provide a .txt file or a directory. 
    This is a required field for the program to work.</p>

<h4>Examples</h4>
<h5>File Input</h5>
<p>This will take the content from the text file and output a HTML file.</p>
<pre>
    ./tgsg -i sample.txt
</pre>

<h5>Directory Input</h5>
<p>This will go though a directory named sample and look for .txt files.</p>
<pre>
    ./tgsg -i sample
</pre>

<h3>Auto-Add Title</h3>
<p>This feature automatically creates an <code>h1</code> tag for the first line if there are two empty spaces after the first line.</p>

<h3>Markdown</h3>
<p>This feature allows the user to input markdown files for conversion into HTML. As of right now the only supported markdown feature is the #/h1 element.</p>

<h4>Example</h4>
<p>Navigate to the folder with the main.cpp through terminal. Enter the following command to allow for Markdown processing.</p>
<pre>
./tgsg -m ./PATH_TO_MARKDOWN_FILE
</pre>
<p>In the file, have the proper syntax for Markdown for header one components:</p>
<pre>
# HELLO WORLD
</pre>

<h3>Language Tag</h3>
<p>This feature allows the user to input an html language tag. The default language is English-Canadian.</p>

<h4>Example</h4>
<p>Navigate to the folder with the main.cpp through terminal. Enter the following command to specify a language. <code>-l</code> or <code>--lang</code> is acceptable.</p>
<pre>
./tgsg -i sample.txt -l fr
</pre>
