/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin processor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"
#include "voices.h"

//==============================================================================
MoobotAudioProcessor::MoobotAudioProcessor()
{
    int nVoices = 4;
    for (int i = nVoices; --i >= 0;)
    {
        synth.addVoice (new MooVoice());
    }
    
    synth.clearSounds();
    synth.addSound (new MooSound());
}

MoobotAudioProcessor::~MoobotAudioProcessor()
{
}

//==============================================================================

const String MoobotAudioProcessor::getName() const
{
    return JucePlugin_Name;
}

bool MoobotAudioProcessor::acceptsMidi() const
{
   #if JucePlugin_WantsMidiInput
    return true;
   #else
    return false;
   #endif
}

bool MoobotAudioProcessor::producesMidi() const
{
   #if JucePlugin_ProducesMidiOutput
    return true;
   #else
    return false;
   #endif
}

double MoobotAudioProcessor::getTailLengthSeconds() const
{
    return 0.0;
}

int MoobotAudioProcessor::getNumPrograms()
{
    return 1;   // NB: some hosts don't cope very well if you tell them there are 0 programs,
                // so this should be at least 1, even if you're not really implementing programs.
}

int MoobotAudioProcessor::getCurrentProgram()
{
    return 0;
}

void MoobotAudioProcessor::setCurrentProgram (int index)
{
}

const String MoobotAudioProcessor::getProgramName (int index)
{
    return String();
}

void MoobotAudioProcessor::changeProgramName (int index, const String& newName)
{
}

//==============================================================================
void MoobotAudioProcessor::prepareToPlay (double sampleRate, int samplesPerBlock)
{
    
    synth.setCurrentPlaybackSampleRate(sampleRate);
}

void MoobotAudioProcessor::releaseResources()
{
    // When playback stops, you can use this as an opportunity to free up any
    // spare memory, etc.
}

#ifndef JucePlugin_PreferredChannelConfigurations
bool MoobotAudioProcessor::setPreferredBusArrangement (bool isInput, int bus, const AudioChannelSet& preferredSet)
{
    // Reject any bus arrangements that are not compatible with your plugin

    const int numChannels = preferredSet.size();

   #if JucePlugin_IsMidiEffect
    if (numChannels != 0)
        return false;
   #elif JucePlugin_IsSynth
    if (isInput || (numChannels != 1 && numChannels != 2))
        return false;
   #else
    if (numChannels != 1 && numChannels != 2)
        return false;

    if (! AudioProcessor::setPreferredBusArrangement (! isInput, bus, preferredSet))
        return false;
   #endif

    return AudioProcessor::setPreferredBusArrangement (isInput, bus, preferredSet);
}
#endif

void MoobotAudioProcessor::processBlock (AudioSampleBuffer& buffer, MidiBuffer& midiMessages) // can be compared with getNextAudioBlock
{
    const int totalNumInputChannels  = getTotalNumInputChannels();
    const int totalNumOutputChannels = getTotalNumOutputChannels();

    for (int i = totalNumInputChannels; i < totalNumOutputChannels; ++i)
        buffer.clear (i, 0, buffer.getNumSamples());

    
    //int numSamples = buffer.getNumSamples ();
    
    for (int channel = 0; channel < totalNumInputChannels; ++channel)
    {

        // ..do something to the data...
    }
//    audioBuffer[0] = buffer.getWritePointer(0);
//    audioBuffer[1] = buffer.getWritePointer(1);

    MidiBuffer processedMidi;
   // int time;
    MidiMessage m;
    
//    
//    for (MidiBuffer::Iterator i (midiMessages); i.getNextEvent(m, time);)
//    {
//        if (m.isNoteOn()) {
//            uint8 newVel = m.getVelocity();
//            float velF = (float)newVel/127.f;
//            
//            synthControl.setParamValue("/main/freq",m.getNoteNumber());
//            synthControl.setParamValue("/main/vel",velF);
//
//            
//        }
//        else if (m.isNoteOff())
//        {
//            synthControl.setParamValue("/main/vel",0.f);
//
//        }
//    }
//    synth[0].compute(numSamples, NULL, audioBuffer);
//    
    //voice.compute(numSamples, NULL, audioBuffer);
    
    synth.renderNextBlock (buffer, midiMessages, 0, buffer.getNumSamples());

}

//==============================================================================
bool MoobotAudioProcessor::hasEditor() const
{
    return true; // (change this to false if you choose to not supply an editor)
}

AudioProcessorEditor* MoobotAudioProcessor::createEditor()
{
    return new MoobotAudioProcessorEditor (*this);
}

//==============================================================================
void MoobotAudioProcessor::getStateInformation (MemoryBlock& destData)
{
    // You should use this method to store your parameters in the memory block.
    // You could do that either as raw data, or use the XML or ValueTree classes
    // as intermediaries to make it easy to save and load complex data.
}

void MoobotAudioProcessor::setStateInformation (const void* data, int sizeInBytes)
{
    // You should use this method to restore your parameters from this memory block,
    // whose contents will have been created by the getStateInformation() call.
}

//==============================================================================
// This creates new instances of the plugin..
AudioProcessor* JUCE_CALLTYPE createPluginFilter()
{
    return new MoobotAudioProcessor();
}
