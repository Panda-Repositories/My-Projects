DWORD WINAPI input(PVOID lvpParameter)
{
    std::string WholeScript = "";
    HANDLE hPipe;
    char buffer[999999];
    DWORD dwRead;
    hPipe = CreateNamedPipe(TEXT("\\\\.\\pipe\\YourPipez"),
        PIPE_ACCESS_DUPLEX | PIPE_TYPE_BYTE | PIPE_READMODE_BYTE,
        PIPE_WAIT,
        1,
        999999,
        999999,
        NMPWAIT_USE_DEFAULT_WAIT,
        NULL);
    while (hPipe != INVALID_HANDLE_VALUE)
    {
        if (ConnectNamedPipe(hPipe, NULL) != FALSE)
        {
            while (ReadFile(hPipe, buffer, sizeof(buffer) - 1, &dwRead, NULL) != FALSE)
            {
                buffer[dwRead] = '\0';
                try {
                    try {
                        WholeScript = WholeScript + buffer;
                    }
                    catch (...) {
                    }
                }
                catch (std::exception e) {

                }
                catch (...) {

                }
            }
                const char* convert = WholeScript.c_str();

                HANDLE hPipe;
                DWORD  cbRead, cbToWrite, cbWritten, dwMode;
                DWORD dwWritten;
                char Buffer[1024];

                hPipe = CreateFile(TEXT("\\\\.\\pipe\\PipeToSend"),
                    GENERIC_READ | GENERIC_WRITE,
                    0,
                    NULL,
                    OPEN_EXISTING,
                    0,
                    NULL);
                if (hPipe != INVALID_HANDLE_VALUE)
                {
                    //WriteFile(hPipe,
                    //    Buffer, //How do I put all the data into a buffer to send over to the client?
                    //    sizeof(Buffer),   // = length of string + terminating '\0' !!!
                    //    &dwWritten,
                    //    NULL);

                    WriteFile(
                        hPipe,                  // pipe handle 
                        convert,             // message 
                        sizeof(Buffer),              // message length 
                        &cbWritten,             // bytes written 
                        NULL);                  // not overlapped 


                    CloseHandle(hPipe);
                }            

            WholeScript = "";
        }
        DisconnectNamedPipe(hPipe);
    }
}