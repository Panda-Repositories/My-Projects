# Registery Coder API
## Easy API for Read and Write Registry Value ( .NET API )_

[![Build Status](https://travis-ci.org/joemccann/dillinger.svg?branch=master)](https://travis-ci.org/joemccann/dillinger)

Compiled from Panda Technology, Credit to StackOverFlaw ( 🙂 )

# Get Value
```
string text = RegisterCoder.RegistryMgr.GetValue(RegisteryFolderName, ValueName)
```

# Example
```
string text = RegisterCoder.RegistryMgr.GetValue("Registry Folder", "Your Value");
MessageBox.Show(text);
```

# ----------------------------------------------------------

# Set Value
```
RegisterCoder.RegistryMgr.SetValue(RegisteryFolderName, ValueName, text);
```

# Example
```
string text = textbox1.text;
RegisterCoder.RegistryMgr.SetValue("Registry Folder", "Your Value", text);
```