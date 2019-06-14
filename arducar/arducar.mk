##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Debug
ProjectName            :=arducar
ConfigurationName      :=Debug
WorkspacePath          :=D:/Workspace/arducar/arducar
ProjectPath            :=D:/Workspace/arducar/arducar
IntermediateDirectory  :=./Debug
OutDir                 := $(IntermediateDirectory)
CurrentFileName        :=
CurrentFilePath        :=
CurrentFileFullPath    :=
User                   :=Clayton
Date                   :=04/05/2019
CodeLitePath           :="C:/Program Files/CodeLite"
LinkerName             :=g++
SharedObjectLinkerName :=g++ -shared -fPIC
ObjectSuffix           :=.o
DependSuffix           :=.o.d
PreprocessSuffix       :=.o.i
DebugSwitch            :=-gstab
IncludeSwitch          :=-I
LibrarySwitch          :=-l
OutputSwitch           :=-o 
LibraryPathSwitch      :=-L
PreprocessorSwitch     :=-D
SourceSwitch           :=-c 
OutputFile             :=$(IntermediateDirectory)/$(ProjectName)
Preprocessors          :=
ObjectSwitch           :=-o 
ArchiveOutputSwitch    := 
PreprocessOnlySwitch   :=-E 
ObjectsFileList        :="arducar.txt"
PCHCompileFlags        :=
MakeDirCommand         :=makedir
RcCmpOptions           := 
RcCompilerName         :=windres
LinkOptions            :=  
IncludePath            :=  $(IncludeSwitch). $(IncludeSwitch). 
IncludePCH             := 
RcIncludePath          := 
Libs                   := 
ArLibs                 :=  
LibPath                := $(LibraryPathSwitch). 

##
## Common variables
## AR, CXX, CC, AS, CXXFLAGS and CFLAGS can be overriden using an environment variables
##
AR       := ar rcus
CXX      := g++
CC       := gcc
CXXFLAGS :=  -g -O0 -Wall $(Preprocessors)
CFLAGS   :=  -g -O0 -Wall $(Preprocessors)
ASFLAGS  := 
AS       := as


##
## User defined environment variables
##
CodeLiteDir:=C:\Program Files\CodeLite
Objects0=$(IntermediateDirectory)/font.cpp$(ObjectSuffix) $(IntermediateDirectory)/nokia.cpp$(ObjectSuffix) $(IntermediateDirectory)/pins.cpp$(ObjectSuffix) $(IntermediateDirectory)/scheduler.cpp$(ObjectSuffix) $(IntermediateDirectory)/range.cpp$(ObjectSuffix) 



Objects=$(Objects0) 

##
## Main Build Targets 
##
.PHONY: all clean PreBuild PrePreBuild PostBuild MakeIntermediateDirs
all: $(OutputFile)

$(OutputFile): $(IntermediateDirectory)/.d $(Objects) 
	@$(MakeDirCommand) $(@D)
	@echo "" > $(IntermediateDirectory)/.d
	@echo $(Objects0)  > $(ObjectsFileList)
	$(LinkerName) $(OutputSwitch)$(OutputFile) @$(ObjectsFileList) $(LibPath) $(Libs) $(LinkOptions)

MakeIntermediateDirs:
	@$(MakeDirCommand) "./Debug"


$(IntermediateDirectory)/.d:
	@$(MakeDirCommand) "./Debug"

PreBuild:


##
## Objects
##
$(IntermediateDirectory)/font.cpp$(ObjectSuffix): font.cpp $(IntermediateDirectory)/font.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "D:/Workspace/arducar/arducar/font.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/font.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/font.cpp$(DependSuffix): font.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/font.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/font.cpp$(DependSuffix) -MM font.cpp

$(IntermediateDirectory)/font.cpp$(PreprocessSuffix): font.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/font.cpp$(PreprocessSuffix) font.cpp

$(IntermediateDirectory)/nokia.cpp$(ObjectSuffix): nokia.cpp $(IntermediateDirectory)/nokia.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "D:/Workspace/arducar/arducar/nokia.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/nokia.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/nokia.cpp$(DependSuffix): nokia.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/nokia.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/nokia.cpp$(DependSuffix) -MM nokia.cpp

$(IntermediateDirectory)/nokia.cpp$(PreprocessSuffix): nokia.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/nokia.cpp$(PreprocessSuffix) nokia.cpp

$(IntermediateDirectory)/pins.cpp$(ObjectSuffix): pins.cpp $(IntermediateDirectory)/pins.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "D:/Workspace/arducar/arducar/pins.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/pins.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/pins.cpp$(DependSuffix): pins.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/pins.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/pins.cpp$(DependSuffix) -MM pins.cpp

$(IntermediateDirectory)/pins.cpp$(PreprocessSuffix): pins.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/pins.cpp$(PreprocessSuffix) pins.cpp

$(IntermediateDirectory)/scheduler.cpp$(ObjectSuffix): scheduler.cpp $(IntermediateDirectory)/scheduler.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "D:/Workspace/arducar/arducar/scheduler.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/scheduler.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/scheduler.cpp$(DependSuffix): scheduler.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/scheduler.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/scheduler.cpp$(DependSuffix) -MM scheduler.cpp

$(IntermediateDirectory)/scheduler.cpp$(PreprocessSuffix): scheduler.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/scheduler.cpp$(PreprocessSuffix) scheduler.cpp

$(IntermediateDirectory)/range.cpp$(ObjectSuffix): range.cpp $(IntermediateDirectory)/range.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "D:/Workspace/arducar/arducar/range.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/range.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/range.cpp$(DependSuffix): range.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/range.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/range.cpp$(DependSuffix) -MM range.cpp

$(IntermediateDirectory)/range.cpp$(PreprocessSuffix): range.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/range.cpp$(PreprocessSuffix) range.cpp


-include $(IntermediateDirectory)/*$(DependSuffix)
##
## Clean
##
clean:
	$(RM) -r ./Debug/


