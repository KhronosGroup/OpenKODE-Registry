# registry.tcl
#
# This is a simple human-readable database defining the OpenKODE extension
# registry. For each extension, it includes an extension number, flags
# if the extension is public, and includes a path to the extension
# specification.
#
# The companion script 'regproc.tcl' uses this to build up the
# extensions portion of the public registry, by copying out only
# the public specifications.

# Removed from OpenKODE 1.0
extension KD_KHR_crypto {
    number      1
    flags       private obsolete
    filename    extensions/KHR/crypto.html
}
extension KD_KHR_perfcounter {
    number      2
    flags       public
    filename    extensions/KHR/perfcounter.html
    header      ../../../openkode/trunk/doc/specs/drafts/draft7473/KHR_perfcounter.h
}
# Removed from OpenKODE 1.0
extension KD_KHR_staticdata {
    number      3
    flags       private obsolete
    filename    extensions/KHR/staticdata.html
}
extension KD_KHR_float64 {
    number      4
    flags       public
    filename    extensions/KHR/float64.html
    header      ../../../openkode/trunk/doc/specs/drafts/draft7473/KHR_float64.h
}
extension KD_KHR_formatted {
    number      5
    flags       public
    filename    extensions/KHR/formatted.html
    header      ../../../openkode/trunk/doc/specs/drafts/draft8259_OpenKODE_1.0.3/KHR_formatted.h
}
extension KD_KHR_thread_storage {
    number      6
    flags       public
    filename    extensions/KHR/thread_storage.html
    header      ../../../openkode/trunk/doc/specs/drafts/draft7473/KHR_thread_storage.h
}
# Removed from OpenKODE 1.0
extension KD_KHR_gles2 {
    number      7
    flags       private incomplete
    filename    extensions/KHR/gles2.html
}
extension KD_ATX_socktype {
    number      8
    flags       public
    filename    extensions/ATX/socktype.html
}
extension KD_ATX_bluetooth {
    number      9
    flags       public
    filename    extensions/ATX/bluetooth.html
    header      extensions/ATX/ATX_bluetooth.h
}
extension KD_ATX_imgdec {
    number      10
    flags       public
    filename    extensions/ATX/imgdec.html
    header      extensions/ATX/ATX_imgdec.h
}
extension KD_ATX_imgdec_png {
    number      11
    flags       public
    filename    extensions/ATX/imgdec_png.html
    header      extensions/ATX/ATX_imgdec_png.h
}
extension KD_ATX_imgdec_jpeg {
    number      12
    flags       public
    filename    extensions/ATX/imgdec_jpeg.html
    header      extensions/ATX/ATX_imgdec_jpeg.h
}
extension KD_ATX_imgdec_pvr {
    number      13
    flags       public
    filename    extensions/ATX/imgdec_pvr.html
    header      extensions/ATX/ATX_imgdec_pvr.h
}
extension KD_ATX_dxtcomp {
    number      14
    flags       public
    filename    extensions/ATX/dxtcomp.html
    header      extensions/ATX/ATX_dxtcomp.h
}
    #?? header      extensions/ACR/ACR_secure_storage.h
extension KD_ACR_secure_storage {
    number      15
    flags       public
    filename    extensions/ACR/ACR_secure_storage.html
}
extension KD_ACR_system_font {
    number      16
    flags       public
    filename    extensions/ACR/ACR_system_font.html
}

# Next free extension number: 17
