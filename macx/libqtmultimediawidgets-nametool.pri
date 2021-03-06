LIBQTMULTIMEDIAWIDGETS_DIR      = QtMultimediaWidgets.framework/Versions/5
LIBQTMULTIMEDIAWIDGETS_FILE     = QtMultimediaWidgets
LIBQTMULTIMEDIAWIDGETS_FILEPATH = $$LIBQTMULTIMEDIAWIDGETS_DIR/$$LIBQTMULTIMEDIAWIDGETS_FILE

LIBQTMULTIMEDIAWIDGETS_INSTALL_NAME_TOOL = install_name_tool -change $$LIBQTMULTIMEDIAWIDGETS_FILEPATH \
            @executable_path/../$$LIBSDIR/$$LIBQTMULTIMEDIAWIDGETS_DIR/$$LIBQTMULTIMEDIAWIDGETS_FILE

contains(QT, multimediawidgets) {
    !isEmpty(nametool.commands) {
        nametool.commands += "&&"
    }

    nametool.commands += $$LIBQTMULTIMEDIAWIDGETS_INSTALL_NAME_TOOL $$OUTFILE
}

LIBQTMULTIMEDIAWIDGETS.path   = $$INSTALLROOT/$$LIBSDIR/$$LIBQTMULTIMEDIAWIDGETS_DIR
LIBQTMULTIMEDIAWIDGETS.files += $$(QTDIR)/lib/$$LIBQTMULTIMEDIAWIDGETS_FILEPATH

LIBQTMULTIMEDIAWIDGETS_INSTALL_NAME_TOOL_ID = install_name_tool -id @executable_path/../$$LIBSDIR/$$LIBQTMULTIMEDIAWIDGETS_DIR/$$LIBQTMULTIMEDIAWIDGETS_FILE \
                        $$INSTALLROOT/$$LIBSDIR/$$LIBQTMULTIMEDIAWIDGETS_DIR/$$LIBQTMULTIMEDIAWIDGETS_FILE
LIBQTMULTIMEDIAWIDGETS_ID.path     = $$INSTALLROOT/$$LIBSDIR/$$LIBQTMULTIMEDIAWIDGETS_DIR
LIBQTMULTIMEDIAWIDGETS_ID.commands = $$LIBQTMULTIMEDIAWIDGETS_INSTALL_NAME_TOOL_ID

