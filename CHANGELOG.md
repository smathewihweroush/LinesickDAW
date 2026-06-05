_Linesick, a free and modern Digital Audio Workspace for electronic music._  
_If you wish a more detailed commit history, check with git._  
_Short changelog explanation:_
_A version header consists of the version, possibly its (nick)name in parenthesis, and the date (in MM/DD/YYYY) of committing the version. If necessary, add the time after a comma as well, format HH:MM (24 hour clock)._
_Every changelog entry starts with a version header and must contain five or possibly less smaller "subtitles" in an specific order, those being (in order):_  
_1. Overview (Mandatory) - short, objective, summarized explanation for the version._
_2. Description (Optional) - longer explanation as well as shared thoughts for the version, should still not be too long (< 25 lines)._
_3. Changes (Mandatory if there are changes) - changes such as modifications, addittions and removals of features which aren't connected to bugs._
_4. Fixes (Mandatory if there are changes) - fixes to previously listed or unlisted bugs, issues and flaws._
_5. Known bugs (Optional\*) - bugs which are notable or of concern_
_\* If a bug is found and is severe (affecting performance, stability, functionality, etc.), it must be noted as a known bug._
_For lines under subtitles, certain symbols as the first character may be used to notate what the line signifies:_
_\+ -> is an addition._
_\- -> is a removal._
_/ -> is a modification or tweak._
_. -> is a fix, or a resolve (?)._
_! -> is a bug, issue or flaw._
_? -> may be used when unsure how to label a line._
_The just explained way of making changelog entries may be subject to changes, and to see the explanation's history, check with git._

### Version 0.0.2a (2.0 pre-alpha) - 05/07/2026
**Overview**:  
Changed the waveform from an undefined square wave to a sine wave with a specific frequency.  
**Changes**:  
/ Changed square wave to sine wave with frequency.  
**Fixes**  
. Added support for different sample rates besides 48000Hz. Previously the BPM would be off.  
**Known bugs**  
! No cross-platform support.
! No channel support besides two channels.

### Version 0.0.1a (1.0 pre-alpha) - 05/01/2026
**Overview**
A simple console tool to playback a gate pattern with BPM applied to a square wave.
**Description**
Pre-alpha versions are not supposed to be out for release. They are far from ready, and these git commits (the versions together with them) will be dumped, if the time comes to release this into the public. I'll probably just leave the old project intact somewhere, but duplicate it, remove the .git folder, and start a new git repo, and I'll push that git repo instead of this mess.
Additionally, pre-alpha versions are *test* versions, mainly to test whether I can even get the minimal Linesick project working (linking Qt, RtAudio, setting up CMake, that kind of stuff).
Additionally #2, this version may or may not be lost to time. It *should* be a commit on this old repo, but maybe it isn't. Even if it isn't, it's really not that big of an archiving loss... Though it *is* the first, and even the *only* version to be lost (thus far)... 
**Changes**
\+ Existence.
**Known bugs**
! No cross-platform support.
! No channel support besides two channels.
! Internal timer functions incorrectly if the sample rate is not 48kHz.
! BPM clicker/metronome is always on the first channel.
