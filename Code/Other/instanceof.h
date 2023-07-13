#ifndef SEMINARSKI_INSTANCEOF_H
#define SEMINARSKI_INSTANCEOF_H

/*
   *
   * Generic function used to check if one class is instance of another one
   * 
*/

template<typename Base, typename T>
inline bool instanceof(T *ptr) {
   return dynamic_cast<Base*>(ptr) != nullptr;
}

#endif