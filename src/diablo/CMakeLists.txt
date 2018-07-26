# add_executable(Diablo
    # main.cpp
    # appfat.cpp
    # automap.cpp
    # capture.cpp
    # codec.cpp
    # control.cpp
    # cursor.cpp
    # dead.cpp
    # debug.cpp
    # diablo.cpp
    # doom.cpp
    # drlg_l1.cpp
    # drlg_l2.cpp
    # drlg_l3.cpp
    # drlg_l4.cpp
    # dthread.cpp
    # dx.cpp
    # effects.cpp
    # encrypt.cpp
    # engine.cpp
    # error.cpp
    # fault.cpp
    # gamemenu.cpp
    # gendung.cpp
    # gmenu.cpp
    # help.cpp
    # init.cpp
    # interfac.cpp
    # inv.cpp
    # items.cpp
    # lighting.cpp
    # loadsave.cpp
    # logging.cpp
    # mainmenu.cpp
    # minitext.cpp
    # missiles.cpp
    # monster.cpp
    # movie.cpp
    # mpqapi.cpp
    # msg.cpp
    # msgcmd.cpp
    # multi.cpp
    # nthread.cpp
    # objects.cpp
    # pack.cpp
    # palette.cpp
    # path.cpp
    # pfile.cpp
    # player.cpp
    # plrmsg.cpp
    # portal.cpp
    # quests.cpp
    # restrict.cpp
    # scrollrt.cpp
    # setmaps.cpp
    # sha.cpp
    # sound.cpp
    # spells.cpp
    # stores.cpp
    # sync.cpp
    # textdat.cpp
    # themes.cpp
    # tmsg.cpp
    # town.cpp
    # towners.cpp
    # track.cpp
    # trigs.cpp
    # wave.cpp
    # world.cpp
# )

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
add_library(DiabloUI STATIC
    # gui/main.cpp
    gui/imgui.cpp
    gui/imgui_demo.cpp
    gui/imgui_draw.cpp
    gui/imgui_impl_glfw.cpp
    gui/imgui_impl_opengl3.cpp
    gui/gamegui.cpp
    )

target_link_libraries(DiabloUI ${HUNTER_LIBS})

# Diablo
add_executable(Diablo
    main.cpp
)
target_link_libraries(Diablo PUBLIC DiabloEngine Renderer DiabloUI ${HUNTER_LIBS})
set_target_properties(Diablo PROPERTIES COMPILE_FLAGS "${FA_COMPILER_FLAGS}")
if(WIN32)
    set_target_properties(Diablo PROPERTIES LINK_FLAGS_RELEASE "/SUBSYSTEM:WINDOWS /ENTRY:mainCRTStartup")
endif()
