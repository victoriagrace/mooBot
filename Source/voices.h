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
#include "mooSynth.h"

#ifndef FAUSTFLOAT
#define FAUSTFLOAT float
#endif

#define MOO_MAXVOICES 8

struct MooSound : public SynthesiserSound
{
    MooSound() {}
    
    bool appliesToNote (int /*midiNoteNumber*/) override        { return true; }
    bool appliesToChannel (int /*midiChannel*/) override        { return true; }
};


struct MooVoice : public SynthesiserVoice
{
    MooVoice() :
    timer(44100),
    isOn(false),
    isRelease(true),
    mode(0)
    {
    }
    
    bool canPlaySound(SynthesiserSound* sound) override
    {
        return dynamic_cast<MooSound*> (sound) != nullptr;
    }
    
    void startNote(int midiNoteNumber, float velocity, SynthesiserSound*, int /* pitchwheel */) override;
    
    void stopNote (float/*velocity*/, bool allowTailOff) override;
    
    void pitchWheelMoved (int /*newValues*/) override
    {
        
    }
    
    void controllerMoved (int /*controllerNumber*/, int /*newValue*/) override
    {
    }
    
    void renderNextBlock (AudioSampleBuffer& outputBuffer, int startSample, int numSamples) override;
    
    void init(double samplingRate);
    void compute(int count, FAUSTFLOAT **in, FAUSTFLOAT **out);
    void setCurrentPlaybackSampleRate(double newRate) override;
    void setVib(float vib);
    void setFormant(float formant);
    void setSpeed(float speed);
    void setEnv(float env);
private:
    mooSynth faustSynth;
    MapUI synthControl;
    float *audioBuffer[2];
    float synth, env;
    long timer;
    bool isOn;
    bool isRelease;
    int mode;
};


#endif  // VOICES_H_INCLUDED
