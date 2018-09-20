
# DiabloEngine
add_library(DiabloEngine STATIC
    engine/window.cpp
    engine/window.h
    engine/gameengine.cpp
    engine/gameengine.h
)
target_link_libraries(DiabloEngine ${HUNTER_LIBS})
set_target_properties(DiabloEngine PROPERTIES COMPILE_FLAGS "${FA_COMPILER_FLAGS}")

# Renderer
add_library(Renderer STATIC
    renderer/shader.cpp
    renderer/shader.h
)
target_link_libraries(Renderer ${HUNTER_LIBS})
set_target_properties(Renderer PROPERTIES COMPILE_FLAGS "${FA_COMPILER_FLAGS}")

# DiabloUI
add_library(GameGUI STATIC
    # gui/main.cpp
    gui/imgui.cpp
    gui/imgui_demo.cpp
    gui/imgui_draw.cpp
    gui/imgui_impl_glfw.cpp
    gui/imgui_impl_opengl3.cpp
    gui/gamegui.cpp
    )

target_link_libraries(GameGUI ${HUNTER_LIBS})

add_executable(Diablo
	main.cpp
    appfat.h
    appfat.cpp
    automap.h
    automap.cpp
    capture.h
    capture.cpp
    codec.h
    codec.cpp
    control.h
    control.cpp
    cursor.h
    cursor.cpp
    dead.h
    dead.cpp
    debug.h
    debug.cpp
    diablo.h
    diablo.cpp
    doom.h
    doom.cpp
    drlg_l1.h
    drlg_l1.cpp
    drlg_l2.h
    drlg_l2.cpp
    drlg_l3.h
    drlg_l3.cpp
    drlg_l4.h
    drlg_l4.cpp
    dthread.h
    dthread.cpp
    dx.h
    dx.cpp
    effects.h
    effects.cpp
    encrypt.h
    encrypt.cpp
    engine.h
    engine.cpp
    error.h
    error.cpp
    fault.h
    fault.cpp
    gamemenu.h
    gamemenu.cpp
    gendung.h
    gendung.cpp
    gmenu.h
    gmenu.cpp
    help.h
    help.cpp
    init.h
    init.cpp
    interfac.h
    interfac.cpp
    inv.h
    inv.cpp
    items.h
    items.cpp
    lighting.h
    lighting.cpp
    loadsave.h
    loadsave.cpp
    logging.h
    logging.cpp
    mainmenu.h
    mainmenu.cpp
    minitext.h
    minitext.cpp
    missiles.h
    missiles.cpp
    monster.h
    monster.cpp
    movie.h
    movie.cpp
    mpqapi.h
    mpqapi.cpp
    msg.h
    msg.cpp
    msgcmd.h
    msgcmd.cpp
    multi.h
    multi.cpp
    nthread.h
    nthread.cpp
    objects.h
    objects.cpp
    pack.h
    pack.cpp
    palette.h
    palette.cpp
    path.h
    path.cpp
    pfile.h
    pfile.cpp
    player.h
    player.cpp
    plrmsg.h
    plrmsg.cpp
    portal.h
    portal.cpp
    quests.h
    quests.cpp
    restrict.h
    restrict.cpp
    scrollrt.h
    scrollrt.cpp
    setmaps.h
    setmaps.cpp
    sha.h
    sha.cpp
    sound.h
    sound.cpp
    spells.h
    spells.cpp
    stores.h
    stores.cpp
    sync.h
    sync.cpp
    textdat.h
    textdat.cpp
    themes.h
    themes.cpp
    tmsg.h
    tmsg.cpp
    town.h
    town.cpp
    towners.h
    towners.cpp
    track.h
    track.cpp
    trigs.h
    trigs.cpp
    wave.h
    wave.cpp
    render.h
    render.cpp
	Diablo.rc
)
target_link_libraries(Diablo PUBLIC Storm DiabloUI PKWare version ${HUNTER_LIBS} DiabloEngine Renderer GameGUI)
SET(EXECUTABLE_OUTPUT_PATH "D:/Diablo")
if(MSVC)
	if(WIN32)
		set_target_properties(Diablo PROPERTIES
			LINK_FLAGS "/SUBSYSTEM:WINDOWS /ENTRY:mainCRTStartup /NXCOMPAT:NO"
			RUNTIME_OUTPUT_DIRECTORY "D:/Diablo"
		)
	endif()
endif()

