#include "TestControl.hpp"
using namespace std;

void TestControl::main()
{
    //  states                               [SYN-G-GEN OUTPUT START] indent(4) $/^E_/$
    //             psggConverterLib.dll converted from psgg-file:TestControl.psgg                                   // *DoNotEdit*
                                                                            // *DoNotEdit*
    /*                                                                      // *DoNotEdit*
                   :: E_0001                                                // *DoNotEdit*
                   ::                                                       // *DoNotEdit*
    */                                                                      // *DoNotEdit*
    int m_i = 0;                                                            // *DoNotEdit*
                                                                            // *DoNotEdit*
                                                                            // *DoNotEdit*
//                                       [SYN-G-GEN OUTPUT END]

//  states                               [SYN-G-GEN OUTPUT START] indent(4) $/^S_/->#memberslist$
    //             psggConverterLib.dll converted from psgg-file:TestControl.psgg                                   // *DoNotEdit*
                                                                            // *DoNotEdit*
    bool m_b = false;                                                       // *DoNotEdit*
                                                                            // *DoNotEdit*
    //                                       [SYN-G-GEN OUTPUT END]




	goto S_START;
	    //  states                                [SYN-G-GEN OUTPUT START] indent(4) $/^S_/$
    //             psggConverterLib.dll converted from psgg-file:TestControl.psgg                                   // *DoNotEdit*
                                                                            // *DoNotEdit*
    /*                                                                      // *DoNotEdit*
                   :: S_0001                                                // *DoNotEdit*
                   ::                                                       // *DoNotEdit*
    */                                                                      // *DoNotEdit*
    S_0001:                                                                 // *DoNotEdit*
    {                                                                       // *DoNotEdit*
        printf("A state-machine is running\n");                             // *DoNotEdit*
        goto S_0003;                                                        // *DoNotEdit*
    }                                                                       // *DoNotEdit*
    /*                                                                      // *DoNotEdit*
                   :: S_0002                                                // *DoNotEdit*
                   ::                                                       // *DoNotEdit*
    */                                                                      // *DoNotEdit*
    S_0002:                                                                 // *DoNotEdit*
    {                                                                       // *DoNotEdit*
        return;                                                             // *DoNotEdit*
        goto S_END;                                                         // *DoNotEdit*
    }                                                                       // *DoNotEdit*
    /*                                                                      // *DoNotEdit*
                   :: S_0003                                                // *DoNotEdit*
                   ::                                                       // *DoNotEdit*
    */                                                                      // *DoNotEdit*
    S_0003:                                                                 // *DoNotEdit*
    {                                                                       // *DoNotEdit*
        m_i = 0;                                                            // *DoNotEdit*
        goto S_0004;                                                        // *DoNotEdit*
    }                                                                       // *DoNotEdit*
    /*                                                                      // *DoNotEdit*
                   :: S_0004                                                // *DoNotEdit*
                   ::                                                       // *DoNotEdit*
    */                                                                      // *DoNotEdit*
    S_0004:                                                                 // *DoNotEdit*
    {                                                                       // *DoNotEdit*
        m_b = m_i  % 2 ==0;                                                 // *DoNotEdit*
        printf_s("%d ",m_i);                                                // *DoNotEdit*
        if (m_b) { goto S_0005; }                                           // *DoNotEdit*
        else { goto S_0006; }                                               // *DoNotEdit*
    }                                                                       // *DoNotEdit*
    /*                                                                      // *DoNotEdit*
                   :: S_0005                                                // *DoNotEdit*
                   ::                                                       // *DoNotEdit*
    */                                                                      // *DoNotEdit*
    S_0005:                                                                 // *DoNotEdit*
    {                                                                       // *DoNotEdit*
        printf_s("EVEN\n");                                                 // *DoNotEdit*
        goto S_0007;                                                        // *DoNotEdit*
    }                                                                       // *DoNotEdit*
    /*                                                                      // *DoNotEdit*
                   :: S_0006                                                // *DoNotEdit*
                   ::                                                       // *DoNotEdit*
    */                                                                      // *DoNotEdit*
    S_0006:                                                                 // *DoNotEdit*
    {                                                                       // *DoNotEdit*
        printf_s("ODD\n");                                                  // *DoNotEdit*
        goto S_0007;                                                        // *DoNotEdit*
    }                                                                       // *DoNotEdit*
    /*                                                                      // *DoNotEdit*
                   :: S_0007                                                // *DoNotEdit*
                   ::                                                       // *DoNotEdit*
    */                                                                      // *DoNotEdit*
    S_0007:                                                                 // *DoNotEdit*
    {                                                                       // *DoNotEdit*
        m_i++;                                                              // *DoNotEdit*
        if (m_i < 10) { goto S_0004; }                                      // *DoNotEdit*
        else { goto S_0002; }                                               // *DoNotEdit*
    }                                                                       // *DoNotEdit*
    /*                                                                      // *DoNotEdit*
                   :: S_END                                                 // *DoNotEdit*
                   ::                                                       // *DoNotEdit*
    */                                                                      // *DoNotEdit*
    S_END:                                                                  // *DoNotEdit*
    exit(0);                                                                // *DoNotEdit*
    /*                                                                      // *DoNotEdit*
                   :: S_START                                               // *DoNotEdit*
                   ::                                                       // *DoNotEdit*
    */                                                                      // *DoNotEdit*
    S_START:                                                                // *DoNotEdit*
    goto S_0001;                                                            // *DoNotEdit*
                                                                            // *DoNotEdit*
                                                                            // *DoNotEdit*
	//                                       [SYN-G-GEN OUTPUT END]
}
