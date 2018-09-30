// myoddweb.directorywatcher.cpp : Defines the exported functions for the DLL application.
//

#include "stdafx.h"
#include "watcher.h"
#include "Importer.h"

namespace myoddweb
{
  namespace directorywatcher
  {
    namespace Interop
    {
      Watcher::Watcher() : _coreWatcher( nullptr )
      {
        _coreWatcher = (CoreWatcher*)Importer(IID_IWatcher1);
      }

      Watcher::~Watcher()
      {
        this->!Watcher();
      }

      Watcher::!Watcher()
      {
        delete _coreWatcher;
        _coreWatcher = nullptr;
      }

      /// <summary>
      /// The path we wish to monitor for changes
      /// </summary>
      /// <param name="path">The path we want to monitor.</param>
      /// <returns>Unique Id used to release/stop monitoring</returns>
      __int64 Watcher::Monitor(String^ path, bool recursive)
      {
        return _coreWatcher == nullptr ? -1 : _coreWatcher->Monitor( path, recursive );
      }
    }
  }
}