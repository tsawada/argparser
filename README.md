# A Minimalist ArgParser

Sometimes you want to add a few command line options to your small C++ programs
without adding any dependencies.  You start looking for a "small", "header-only"
argparser libraries, but you notice that many of them are a few hundreds of
lines of code, which is larger than your program itself!

This ArgParser is an example of how you can parse flags with less than 10 lines
of actual code.  This parser has lots of limitations: this parser can only parse
`--double-dash=string` style flags, flags must come first then args, and does
not generate help messages.  But it might be good enough for small tools with
just a few programmer users, and I'm sure it is easy to implement those features
as you need.

This code is in the public domain, and is a snippet for your inspiration rather
than a library to copy as is.  Feel free to modify and expand to fit your needs.
