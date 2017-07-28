<?php
$static_title = 'Khronos OpenKODE Registry';

include_once("../../assets/static_pages/khr_page_top.php");
?>

<p> The OpenKODE Registry contains specifications of the core API and
    headers, optional OpenKODE extensions and headers, points to other
    Khronos APIs required by a conformant OpenKODE implementation, and
    includes some related documentation. </p>

<h6> OpenKODE Core API Specification and Headers </h6>

<p> The current version of OpenKODE is OpenKODE 1.0.3.
    The specification package was released on May 20, 2009. </p>

<ul>
<li> <a href="specs/openkode.1.0.3.pdf"> OpenKODE 1.0.3 Specification
     (May 20, 2009). </a>
     <ul>
     <li> <a href="api/1.0.3/kd.h"> kd.h </a> for OpenKODE 1.0.3. </li>
     <li> <a href="api/1.0.3/kdplatform.h"> kdplatform.h </a> for
          OpenKODE 1.0.3. </li>
     </ul> </li>
</ul>

<hr></hr>
<br>

<h6> Archived Specifications </h6>

<p> OpenKODE 1.0.2 was updated on February 23, 2009. </p>

<ul>
<li> <a href="specs/openkode.1.0.2.pdf"> OpenKODE 1.0.2 Specification
     (February 23, 2009). </a>
     <ul>
     <li> <a href="api/1.0.2/kd.h"> kd.h </a> for OpenKODE 1.0.2. </li>
     <li> <a href="api/1.0.2/kdplatform.h"> kdplatform.h </a> for
          OpenKODE 1.0.2. </li>
     </ul> </li>
</ul>

<hr></hr>
<br>

<p> OpenKODE 1.0.1 was released on June 16, 2008. </p>

<ul>
<li> <a href="specs/openkode.1.0.1.pdf"> OpenKODE 1.0.1 Specification
     (June 16, 2008). </a>
     <ul>
     <li> <a href="api/1.0.1/kd.h"> kd.h </a> for OpenKODE 1.0.1. </li>
     <li> <a href="api/1.0.1/kdplatform.h"> kdplatform.h </a> for
          OpenKODE 1.0.1. </li>
     </ul> </li>
</ul>

<p> OpenKODE 1.0 was released on February 11, 2008: </p>

<ul>
<li> <a href="specs/openkode.1.0.pdf"> OpenKODE 1.0 Specification </a>
     (February 11, 2008).
     <ul>
     <li> <a href="api/1.0/kd.h"> kd.h </a> for OpenKODE 1.0. </li>
     <li> <a href="api/1.0/kdplatform.h"> kdplatform.h </a> for OpenKODE
          1.0. </li>
     </ul> </li>
</ul>

<p> Prior to OpenKODE 1.0 being released, two <i>Provisional</i>
    versions of the specification and header files were made available
    for public feedback. These versions are retained here for archival
    purposes, but are superseded by OpenKODE 1.0. All implementations of
    OpenKODE should use released versions (1.0.1 or 1.0) of the
    Specification and headers. </p>

<p> The OpenKODE 1.0 <i>Provisional (Revision 2)</i> specification
    package was released in January, 2008: </p>

<ul>
<li> <a href="specs/openkode.1.0.provisional.rev2.pdf"> OpenKODE 1.0
     Provisional (Revision 2) Specification </a> (updated by the
     OpenKODE Working Group on December 11, 2007).
     <ul>
     <li> <a href="api/provisional.rev2/kd.h"> kd.h </a> for OpenKODE
          1.0 Provisional (Revision 2). </li>
     <li> <a href="api/provisional.rev2/kdplatform.h"> kdplatform.h </a>
          for OpenKODE 1.0 Provisional (Revision 2). </li>
     </ul> </li>
</ul>

<p> The OpenKODE 1.0 Provisional (Revision 1) specification package was
    released in April 2007. </p>

<ul>
<li> <a href="specs/openkode.1.0.provisional.rev1.pdf"> OpenKODE 1.0
     Provisional (Revision 1) Specification </a> (updated by the
     OpenKODE Working Group on April 2, 2007; first ratified by the
     Khronos Board of Promoters on February 8, 2007)
     <ul>
     <li> <a href="api/provisional.rev1/kd.h"> kd.h </a> for OpenKODE
          1.0 Provisional (Revision 1). </li>
     <li> <a href="api/provisional.rev1/kdplatform.h"> kdplatform.h </a>
          for OpenKODE 1.0 Provisional (Revision 1). </li>
     </ul> </li>
</ul>

<hr></hr>
<br>

<h6> Related APIs </h6>

<p> OpenKODE includes by reference a number of other Khronos APIs,
    listed below. </p>

<ul>
<li> <a href="../egl/specs/eglspec.1.3.pdf">
     EGL 1.3 Specification </a> (approved December 4, 2006). </li>
<li> Extensions to EGL 1.3, including:
     <ul>
     <li> <a href="../egl/extensions/KHR/EGL_KHR_image.txt">
          EGL_KHR_image </a> </li>
     <li> <a href="../egl/extensions/KHR/EGL_KHR_vg_parent_image.txt">
          EGL_KHR_vg_parent_image </a> </li>
     <li> <a href="../egl/extensions/KHR/EGL_KHR_gl_image.txt">
          EGL_KHR_gl_texture_2D_image </a> </li>
     <li> <a href="../egl/extensions/KHR/EGL_KHR_gl_image.txt">
          EGL_KHR_gl_texture_cubemap_image </a> </li>
     <li> <a href="../egl/extensions/KHR/EGL_KHR_gl_image.txt">
          EGL_KHR_gl_texture_3D_image </a> </li>
     <li> <a href="../egl/extensions/KHR/EGL_KHR_gl_image.txt">
          EGL_KHR_gl_renderbuffer_image </a> </li>
     <li> <a href="../egl/extensions/KHR/EGL_KHR_lock_surface.txt">
          EGL_KHR_lock_surface </a> (added to OpenKODE 1.0 Provisional
          on April 2, 2007) </li>
     </ul> </li>
<li> OpenGL ES 1.1
     <a href="http://www.khronos.org/registry/gles/specs/1.1/es_full_spec.1.1.10.pdf">
     Full Specification </a> and
     <a href="http://www.khronos.org/registry/gles/specs/1.1/es_cm_spec_1.1.10.pdf">
     Difference Specification </a> (April 4, 2007). </li>
<li> Extensions to OpenGL ES 1.1, including:
     <ul>
     <li> <a href="../gles/extensions/OES/OES_egl_image.txt">
          GL_OES_egl_image </a> </li>
     </ul> </li>
<li> <a href="http://www.khronos.org/openvg/"> OpenVG 1.0.1
     Specification </a> (amended January 26, 2007). </li>
<li> Extensions to OpenVG 1.0.1, including:
     <ul>
     <li> <a href="../vg/extensions/KHR/VG_KHR_EGL_image.txt">
          VG_KHR_EGL_image </a> </li>
     </ul> </li>
</ul>

<p> See the <a href="http://www.khronos.org/developers/specs/">
    Khronos.org Developer Pages </a> and the <a
    href="http://www.khronos.org/registry/"> Khronos Registry </a> for
    additional material, including headers for EGL, OpenGL ES, OpenVG,
    and other Khronos APIs. </p>

<h6> Enumerant Registry </h6>

<p> The database from which OpenKODE enumerant ranges are reserved is
    called <tt><a href="api/kodeenum.txt">kodeenum.txt</a></tt>. </p>


<h6> <a name="otherextspecs"></a>
     Extension Specifications</h6>
<ol>
<li value=2> <a href="extensions/KHR/perfcounter.html">KD_KHR_perfcounter</a> (<a href="api/KHR/KHR_perfcounter.h">KHR_perfcounter.h</a>)
</li>
<li value=4> <a href="extensions/KHR/float64.html">KD_KHR_float64</a> (<a href="api/KHR/KHR_float64.h">KHR_float64.h</a>)
</li>
<li value=5> <a href="extensions/KHR/formatted.html">KD_KHR_formatted</a> (<a href="api/KHR/KHR_formatted.h">KHR_formatted.h</a>)
</li>
<li value=6> <a href="extensions/KHR/thread_storage.html">KD_KHR_thread_storage</a> (<a href="api/KHR/KHR_thread_storage.h">KHR_thread_storage.h</a>)
</li>
<li value=8> <a href="extensions/ATX/socktype.html">KD_ATX_socktype</a>
</li>
<li value=9> <a href="extensions/ATX/bluetooth.html">KD_ATX_bluetooth</a> (<a href="api/ATX/ATX_bluetooth.h">ATX_bluetooth.h</a>)
</li>
<li value=10> <a href="extensions/ATX/imgdec.html">KD_ATX_imgdec</a> (<a href="api/ATX/ATX_imgdec.h">ATX_imgdec.h</a>)
</li>
<li value=11> <a href="extensions/ATX/imgdec_png.html">KD_ATX_imgdec_png</a> (<a href="api/ATX/ATX_imgdec_png.h">ATX_imgdec_png.h</a>)
</li>
<li value=12> <a href="extensions/ATX/imgdec_jpeg.html">KD_ATX_imgdec_jpeg</a> (<a href="api/ATX/ATX_imgdec_jpeg.h">ATX_imgdec_jpeg.h</a>)
</li>
<li value=13> <a href="extensions/ATX/imgdec_pvr.html">KD_ATX_imgdec_pvr</a> (<a href="api/ATX/ATX_imgdec_pvr.h">ATX_imgdec_pvr.h</a>)
</li>
<li value=14> <a href="extensions/ATX/dxtcomp.html">KD_ATX_dxtcomp</a> (<a href="api/ATX/ATX_dxtcomp.h">ATX_dxtcomp.h</a>)
</li>
<li value=15> <a href="extensions/ACR/ACR_secure_storage.html">KD_ACR_secure_storage</a>
</li>
<li value=16> <a href="extensions/ACR/ACR_system_font.html">KD_ACR_system_font</a>
</li>
</ol>


<h6> Providing Feedback on the Registry </h6>

<p> Khronos welcomes comments and bug reports. To provide feedback on the
    OpenKODE registry itself (such as reporting missing content, bad links,
    etc.), file an issue in the <a
    href="https://github.com/KhronosGroup/OpenKODE-Registry/issues">
    OpenKODE-Registry </a> Github project. </p>

<p> For the OpenKODE API, extensions, and headers, file a bug on the <a
    href="http://www.khronos.org/bugzilla/"> Khronos Bugzilla </a>. Make
    sure to fill in the &quot;Product&quot; field in the bug entry form as
    &quot;OpenKODE&quot;, and pick appropriate values for the Component and
    other fields. </p>


<?php include_once("../../assets/static_pages/khr_page_bottom.php"); ?>
</body>
</html>
