<p align="center">
  <a href="https://vimeo.com/188797891" target="_blank">
    <img src="https://github.com/PJCSpencer/CecropiaGraph/blob/master/preview_20200825-0951.png" alt="CecropiaGraph Demonstration"/>
  </a>
  A general-purpose, 2d node graph GUI using Qt.
</p>

# About
Cecropia Graph is a simple 2d node graph interface. Started early 2016 its indirectly motivated by the desire to be creative and discover something organic, something different, while maintaining a practical focus for the user. I had also wanted to develop new skills for some time so this represents my first project written in modern C++, first using the Qt framework. 

For the visible future it will continue as a work-in-progress with attention going towards:

- Plug dragging and reordering<br>
- Animated collapsible nodes<br>
- Multiple line type connectors

# Installation
The project was developed as tested using Xcode 7.0, Qt 5.5. If they wish most experienced developers should be comfortable stripping out the code and building with Qt-Creator. Hopefully this won't require too much work but it would be great to learn of any interesting challenges. The NodeLibrary::rootDirectory path is used to dynamically load application resources and should be modified to reflect the target file system.

# Documentation
All code files in the "spencers-dm/cecropia-graph" directory are documented with doxygen comments. To generate the html documentation run the provided configuration file using the following command:
~~~~
doxygen docs
~~~~

# Contribution
These will be most welcome once a robust version with completed features has been developed. Creative technical expression and solid basics are characteristics I would like the project to reflect.

# License
Sources are released under the GNU Lesser General Public License v.3(“LGPL”).
