# forsaken

The Forsaken source code.

This is a fork of the first commit to the [ForsakenX](https://github.com/ForsakenX/forsaken) project.
The original Forsaken game was built on Windows with the DirectX 6 SDK.
The ForsakenX project goals are to get Forsaken running on a number of other platforms, including Linux and OSX.
As such, that code base is a substantial port to a different tool chain and set of libraries.
It must now be compiled with gcc instead of MSVC and uses SDL and other libraries instead of DirectX, even on Windows.

This project is an attempt to get the original game running against modern versions of Windows, using the latest tools.
Another goal is to keep the source code as close to the original as possible, to serve as a living historical record.
If it makes sense to add substantial new features, we may use dedicated branches for that.