# OpenKODE-Registry

The OpenKODE-Registry repository contains the OpenKODE API and Extension
Registry, including specifications and header files.

It is also used as a backing store for the web view of the registry at
https://www.khronos.org/registry/kode/ ; commits to the master branch of
this repository will be reflected there.

In the past, the OpenKODE registry was maintained in a public Subversion
repository. The history in that repository has not been imported to github,
but it is still available at
https://cvs.khronos.org/svn/repos/registry/trunk/public/kode/ .

Interesting files in this repository include:

* index.php - toplevel index page for the web view. This relies on PHP
  include files found elsewhere on www.khronos.org and so is not very useful
  in isolation.
* registry.txt - Extension number and filename registry.
* api/ - OpenKODE header files
** api/kodeenum.txt - Enumerant registry
* extensions/ - OpenKODE extension specifications, grouped into
  vendor-specific subdirectories.
* specs/ - OpenKODE specification documents.


## Adding Extension Specifications

Extension specification documents can be added by proposing a pull request
to master, adding the specification .html file under
extensions/<vendor>/filename.html . If there are corresponding header files
and/or Docbook source markup files, place them in the same directory. You
must also:

* Allocate an extension number in registry.txt (follow the existing
  extension examples, search for "Next free extension number", and use the
  lowest available extension number. Increment the free extension number.
* Include that extension number in the extension specification document.
* Add a link from the extensions section of index.php to the extension
  document, using the specified extension number, so it shows up in the web
  view.
