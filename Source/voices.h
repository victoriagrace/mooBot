/*
  ==============================================================================

    voices.h
    Created: 22 Oct 2016 3:52:34pm
    Author:  Victoria Grace

  ==============================================================================
*/

#ifndef VOICES_H_INCLUDED
#define VOICES_H_INCLUDED
#include "../JuceLibraryCode/JuceHeader.h"


struct MooSound : public SynthesiserSound
{
    MooSound() {}
    
    bool appliesToNote (int /*midiNoteNumber*/) override        { return true; }
    bool appliesToChannel (int /*midiChannel*/) override        { return true; }
};





#endif  // VOICES_H_INCLUDED
