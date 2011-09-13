#include <iostream>
 
#include "wav_in.h"
#include "wav_out.h"
 
int main(int argc, char** argv)
{
  if(argc!=3) {
    std::cerr<<"Reads in a .wav file and writes it out.\n"
      << "         by Dr. Chris Taylor, t a y l o r@msoe.edu, 6-26-2002\n"
      << "         Makes use of utility code written by Dr. Fred DePiero\n\n"
      << "Usage: " << argv[0] << " infilename.wav outfilename.wav\n";
  } else {
    WAV_IN infile(argv[1]);
    double sampleRate = infile.get_sample_rate_hz();
    unsigned int bitsPerSample = infile.get_bits_per_sample();
    unsigned int channels = infile.get_num_channels();
    WAV_OUT outfile(sampleRate, bitsPerSample, channels);
    while(infile.more_data_available()) {
      double data = infile.read_current_input();
      // If this were a real application, you'd probably do something 
      //  to the data here. 
      outfile.write_current_output(data);
    }
    outfile.save_wave_file(argv[2]);
  }
  return 0;
}
