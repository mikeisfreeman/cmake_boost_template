
set(CmakeBoostTemplate_H
# Add header files here
)

# Form the full path to the source files...
PREPEND(CmakeBoostTemplate_H)
# ... and pass the variable to the parent scope.
set(CmakeBoostTemplate_H ${CmakeBoostTemplate_H}  PARENT_SCOPE)