/*
  ==============================================================================

  License Valid JUCE
 
  Call an end point the check if the serial number is valid or not
 
  ==============================================================================
*/

#include "../JuceLibraryCode/JuceHeader.h"


//==============================================================================
int main (int argc, char* argv[])
{
    // info
    const char *url_str = "https://api.keyzy.io/v2/licenses/valid";
    String app_id = "your-app_id";
    String api_key = "your-read-only-api_key";
    String serial = "serial-number";
    String code = "product-code";
    String host_id = "";
    
    // preparing the string
    String postdata_str = "app_id=" + app_id + "&api_key=" + api_key +
        "&serial=" + serial + "&code=" + code + "&host_id=" + host_id;
    
    // get
    URL url(url_str);
    StringPairArray responseHeaders;
    int statusCode = 0;
    
    url = url.withPOSTData(postdata_str);
    MemoryBlock response;
    std::unique_ptr<InputStream>stream(url.createInputStream(true,    // POST method
                                                             nullptr, //
                                                             nullptr, //
                                                             {},      // no header
                                                             30000,   // wait maximum 30 seconds
                                                             &responseHeaders,
                                                             &statusCode));

    if (stream == nullptr)
        return -1;
    
    stream->readIntoMemoryBlock(response);

    if (statusCode != 200)
    {
        return -2;
    }

    // OK
    std::cout << response.toString();
 
    return 0;
}
