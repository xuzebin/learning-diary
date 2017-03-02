#!/usr/bin/env python

# A simple example of observer pattern (modified from https://en.wikipedia.org/wiki/Observer_pattern)

class Observable:
    def __init__(self):
        self.__observers = []

    def register_observer(self, observer):
        self.__observers.append(observer)
        
    def notify_observers(self, *args, **kwargs):
        for observer in self.__observers:
            observer.notify(self, *args, **kwargs)

class Observer:
    def notify(self, observable, *args, **kwargs):
        print('Got', args, kwargs, 'From', observable)

if __name__ == "__main__":
    subject = Observable()
    observer = Observer()
    subject.register_observer(observer)
    subject.notify_observers('msg')
