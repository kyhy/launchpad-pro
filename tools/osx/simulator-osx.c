/******************************************************************************
 
 Copyright (c) 2015, Focusrite Audio Engineering Ltd.
 All rights reserved.
 
 Redistribution and use in source and binary forms, with or without
 modification, are permitted provided that the following conditions are met:
 
 * Redistributions of source code must retain the above copyright notice, this
 list of conditions and the following disclaimer.
 
 * Redistributions in binary form must reproduce the above copyright notice,
 this list of conditions and the following disclaimer in the documentation
 and/or other materials provided with the distribution.
 
 * Neither the name of Focusrite Audio Engineering Ltd., nor the names of its
 contributors may be used to endorse or promote products derived from
 this software without specific prior written permission.
 
 THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
 FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
 SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
 CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
 OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 
 *****************************************************************************/

#include <stdio.h>
#include "app.h"

// ____________________________________________________________________________
//
// Simulator "hal".  This lets you exercise your device code without having to upload
// it to the hardware, which also means you can debug it interactively.
// ____________________________________________________________________________

void hal_plot_led(u8 type, u8 index, u8 red, u8 green, u8 blue)
{
	// wire this up to MIDI out...
}

void hal_send_midi(u8 port, u8 status, u8 d1, u8 d2)
{
	// send this up a virtual MIDI port?
}

void hal_send_sysex(u8 port, const u8* data, u16 length)
{
	// as above, or just dump to console?
}

// ____________________________________________________________________________
//
// App event wrappers - these just log to the console.  Would be nice to wire
// these up to a MIDI input from the real Launchpad Pro!
// ____________________________________________________________________________

static void sim_app_init()
{
	app_init();
}

static void sim_app_surface_event(u8 type, u8 index, u8 value)
{
	app_surface_event(type, index, value);
}

static void sim_app_midi_event(u8 port, u8 status, u8 d1, u8 d2)
{
	app_midi_event(port, status, d1, d2);
}

static void sim_app_timer_event()
{
	app_timer_event();
}

// ____________________________________________________________________________

int main(int argc, char * argv[])
{
	// open MIDI ports and wire them up
	
	// init the app
	sim_app_init();
	
	// start the terrible busywaiting timer loop
	for (;;)
	{
		
	}
	
	return 0;
}