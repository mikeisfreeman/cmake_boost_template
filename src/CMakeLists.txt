
set(CmakeBoostTemplate_CPP
    main.cpp
)

# full path to the source files. (PREPEND is a function defined in the CmakeLists.txt file in the root dir)
PREPEND(CmakeBoostTemplate_CPP)

# ... and pass the variable to the parent scope.
set(CmakeBoostTemplate_CPP ${CmakeBoostTemplate_CPP}  PARENT_SCOPE)