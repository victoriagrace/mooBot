/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"
#include "mooSynth.h"
//==============================================================================
MoobotAudioProcessorEditor::MoobotAudioProcessorEditor (MoobotAudioProcessor& p)
    : AudioProcessorEditor (&p), processor (p)
{
    // Make sure that before the constructor has finished, you've set the
    // editor's size to whatever you need it to be.
    addAndMakeVisible (slider4 = new Slider ("slider4"));
    slider4->setRange (0, 1);
    slider4->setSliderStyle (Slider::LinearBar);
    slider4->setTextBoxStyle (Slider::TextBoxLeft, false, 80, 20);
    slider4->setColour (Slider::backgroundColourId, Colour (0xff000097));
    slider4->setColour (Slider::rotarySliderFillColourId, Colour (0xffb925c9));
    slider4->addListener (this);
    
    addAndMakeVisible (slider1 = new Slider ("slider1"));
    slider1->setRange (10, 10000, 0);
    slider1->setSliderStyle (Slider::LinearBar);
    slider1->setTextBoxStyle (Slider::TextBoxLeft, false, 80, 20);
    slider1->setColour (Slider::backgroundColourId, Colour (0xff000097));
    slider1->setColour (Slider::rotarySliderFillColourId, Colour (0xff23a31b));
    slider1->addListener (this);
    
    addAndMakeVisible (slider5 = new Slider ("slider5"));
    slider5->setRange (0, 10, 0);
    slider5->setSliderStyle (Slider::LinearBar);
    slider5->setTextBoxStyle (Slider::TextBoxLeft, false, 80, 20);
    slider5->setColour (Slider::backgroundColourId, Colour (0xff000097));
    slider5->setColour (Slider::rotarySliderFillColourId, Colour (0xff00e1ff));
    slider5->addListener (this);
    
    addAndMakeVisible (slider2 = new Slider ("slider2"));
    slider2->setRange (0, 10, 0);
    slider2->setSliderStyle (Slider::LinearBarVertical);
    slider2->setTextBoxStyle (Slider::TextBoxLeft, false, 80, 20);
    slider2->setColour (Slider::backgroundColourId, Colour (0xff000097));
    slider2->setColour (Slider::rotarySliderFillColourId, Colour (0xffda00ff));
    slider2->addListener (this);
    
    addAndMakeVisible (slider3 = new Slider ("slider3"));
    slider3->setRange (0, 10, 0);
    slider3->setSliderStyle (Slider::LinearBarVertical);
    slider3->setTextBoxStyle (Slider::TextBoxLeft, false, 80, 20);
    slider3->setColour (Slider::backgroundColourId, Colour (0xff000097));
    slider3->setColour (Slider::rotarySliderFillColourId, Colour (0xff0d9525));
    slider3->addListener (this);
    
    
    setSize (380, 550);
}

MoobotAudioProcessorEditor::~MoobotAudioProcessorEditor()
{
    slider4 = nullptr;
    slider1 = nullptr;
    slider5 = nullptr;
    slider2 = nullptr;
    slider3 = nullptr;
}

//==============================================================================
void MoobotAudioProcessorEditor::paint (Graphics& g)
{
    
    g.fillAll (Colours::black);
    
    g.setColour (Colour (0xff352aa5));
    g.fillPath (internalPath1);
    
    g.setColour (Colour (0xff201ccb));
    g.fillRect (260, 108, 20, 20);
    
    g.setColour (Colour (0xff010101));
    g.fillPath (internalPath2);
    
    g.setColour (Colour (0xff3d3e43));
    g.fillPath (internalPath3);
    
    g.setColour (Colour (0xff3d3e43));
    g.fillPath (internalPath4);
    
    g.setColour (Colour (0xff252596));
    g.fillPath (internalPath5);
    
    g.setColour (Colour (0xff352aa5));
    g.fillPath (internalPath6);
    
    g.setColour (Colours::black);
    g.fillPath (internalPath7);
    
    g.setColour (Colours::black);
    g.fillPath (internalPath8);
    
    g.setColour (Colour (0xff201ccb));
    g.fillPath (internalPath9);
    
    g.setColour (Colour (0xff201ccb));
    g.fillPath (internalPath10);
    
    g.setColour (Colour (0xff352aa5));
    g.fillPath (internalPath11);
    
    g.setColour (Colour (0xff352aa5));
    g.fillPath (internalPath12);
    
    g.setColour (Colours::black);
    g.fillPath (internalPath13);
    
    g.setColour (Colours::black);
    g.fillPath (internalPath14);
}



    void MoobotAudioProcessorEditor::resized()
{
    slider4->setBounds (240, 48, 120, 32);
    slider1->setBounds (16, 48, 120, 32);
    slider5->setBounds (128, 272, 112, 32);
    slider2->setBounds (128, 376, 32, 112);
    slider3->setBounds (224, 376, 32, 112);
    internalPath1.clear();
    internalPath1.startNewSubPath (68.0f, 276.0f);
    internalPath1.lineTo (68.0f, 76.0f);
    internalPath1.lineTo (308.0f, 76.0f);
    internalPath1.lineTo (308.0f, 276.0f);
    internalPath1.closeSubPath();
    
    internalPath2.clear();
    internalPath2.startNewSubPath (186.0f, 156.0f);
    internalPath2.cubicTo (222.0f, 156.0f, 252.0f, 179.0f, 252.0f, 208.0f);
    internalPath2.cubicTo (252.0f, 237.0f, 222.0f, 260.0f, 186.0f, 260.0f);
    internalPath2.cubicTo (150.0f, 260.0f, 120.0f, 237.0f, 120.0f, 208.0f);
    internalPath2.cubicTo (120.0f, 179.0f, 150.0f, 156.0f, 186.0f, 156.0f);
    internalPath2.closeSubPath();
    
    internalPath3.clear();
    internalPath3.startNewSubPath (150.0f, 172.0f);
    internalPath3.cubicTo (160.0f, 172.0f, 168.0f, 176.0f, 168.0f, 182.0f);
    internalPath3.cubicTo (168.0f, 188.0f, 160.0f, 192.0f, 150.0f, 192.0f);
    internalPath3.cubicTo (140.0f, 192.0f, 132.0f, 188.0f, 132.0f, 182.0f);
    internalPath3.cubicTo (132.0f, 176.0f, 140.0f, 172.0f, 150.0f, 172.0f);
    internalPath3.closeSubPath();
    
    internalPath4.clear();
    internalPath4.startNewSubPath (222.0f, 172.0f);
    internalPath4.cubicTo (232.0f, 172.0f, 240.0f, 176.0f, 240.0f, 182.0f);
    internalPath4.cubicTo (240.0f, 188.0f, 232.0f, 192.0f, 222.0f, 192.0f);
    internalPath4.cubicTo (212.0f, 192.0f, 204.0f, 188.0f, 204.0f, 182.0f);
    internalPath4.cubicTo (204.0f, 176.0f, 212.0f, 172.0f, 222.0f, 172.0f);
    internalPath4.closeSubPath();
    
    internalPath5.clear();
    internalPath5.startNewSubPath (132.0f, 232.0f);
    internalPath5.lineTo (132.0f, 220.0f);
    internalPath5.lineTo (240.0f, 220.0f);
    internalPath5.lineTo (240.0f, 232.0f);
    internalPath5.closeSubPath();
    
    internalPath6.clear();
    internalPath6.startNewSubPath (100.0f, 372.0f);
    internalPath6.lineTo (100.0f, 300.0f);
    internalPath6.lineTo (280.0f, 300.0f);
    internalPath6.lineTo (280.0f, 372.0f);
    internalPath6.closeSubPath();
    
    internalPath7.clear();
    internalPath7.startNewSubPath (260.0f, 136.0f);
    internalPath7.lineTo (260.0f, 100.0f);
    internalPath7.lineTo (296.0f, 100.0f);
    internalPath7.lineTo (296.0f, 136.0f);
    internalPath7.closeSubPath();
    
    internalPath8.clear();
    internalPath8.startNewSubPath (84.0f, 136.0f);
    internalPath8.lineTo (84.0f, 100.0f);
    internalPath8.lineTo (120.0f, 100.0f);
    internalPath8.lineTo (120.0f, 136.0f);
    internalPath8.closeSubPath();
    
    internalPath9.clear();
    internalPath9.startNewSubPath (268.0f, 128.0f);
    internalPath9.lineTo (268.0f, 108.0f);
    internalPath9.lineTo (288.0f, 108.0f);
    internalPath9.lineTo (288.0f, 128.0f);
    internalPath9.closeSubPath();
    
    internalPath10.clear();
    internalPath10.startNewSubPath (92.0f, 128.0f);
    internalPath10.lineTo (92.0f, 108.0f);
    internalPath10.lineTo (112.0f, 108.0f);
    internalPath10.lineTo (112.0f, 128.0f);
    internalPath10.closeSubPath();
    
    internalPath11.clear();
    internalPath11.startNewSubPath (212.0f, 520.0f);
    internalPath11.lineTo (212.0f, 476.0f);
    internalPath11.lineTo (288.0f, 476.0f);
    internalPath11.lineTo (288.0f, 520.0f);
    internalPath11.closeSubPath();
    
    internalPath12.clear();
    internalPath12.startNewSubPath (92.0f, 520.0f);
    internalPath12.lineTo (92.0f, 476.0f);
    internalPath12.lineTo (168.0f, 476.0f);
    internalPath12.lineTo (168.0f, 520.0f);
    internalPath12.closeSubPath();
    
    internalPath13.clear();
    internalPath13.startNewSubPath (212.0f, 500.0f);
    internalPath13.lineTo (212.0f, 364.0f);
    internalPath13.lineTo (264.0f, 364.0f);
    internalPath13.lineTo (264.0f, 500.0f);
    internalPath13.closeSubPath();
    
    internalPath14.clear();
    internalPath14.startNewSubPath (116.0f, 500.0f);
    internalPath14.lineTo (116.0f, 364.0f);
    internalPath14.lineTo (168.0f, 364.0f);
    internalPath14.lineTo (168.0f, 500.0f);
    internalPath14.closeSubPath();

}

void MoobotAudioProcessorEditor::sliderValueChanged (Slider* sliderThatWasMoved)
{
    //[UsersliderValueChanged_Pre]
    //[/UsersliderValueChanged_Pre]
    
    if (sliderThatWasMoved == slider4)
    {
        //[UserSliderCode_slider4] -- add your slider handling code here..
        synthControl.setParamValue("/main/formant", slider4->getValue());
    }
    else if (sliderThatWasMoved == slider1)
    {
        //[UserSliderCode_slider1] -- add your slider handling code here..
        //[/UserSliderCode_slider1]
        for(int v = 0; v < MOO_MAXVOICES; v++) {
            processor.voice[v].setCutoff(slider1->getValue());
        }
    }
    else if (sliderThatWasMoved == slider5)
    {
        //[UserSliderCode_slider5] -- add your slider handling code here..
        //[/UserSliderCode_slider5]
    }
    else if (sliderThatWasMoved == slider2)
    {
        //[UserSliderCode_slider2] -- add your slider handling code here..
        //[/UserSliderCode_slider2]
    }
    else if (sliderThatWasMoved == slider3)
    {
        //[UserSliderCode_slider3] -- add your slider handling code here..
        //[/UserSliderCode_slider3]
    }
    
    //[UsersliderValueChanged_Post]
    //[/UsersliderValueChanged_Post]
}
