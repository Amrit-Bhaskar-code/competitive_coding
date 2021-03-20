# https://aonecode.com/amazon-online-assessment-lru

from collections import OrderedDict

def lruCacheMisses(num: int, pages: list, maxCacheSize: int) -> int:
    cache = OrderedDict()
    output = 0
    for i in pages:
        if i not in cache.keys():
            output+=1
            cache[i] = i
            cache.move_to_end(i) 
            if len(cache) > maxCacheSize:
                cache.popitem(last = False)
        else:
            cache.move_to_end(i)
        
    return output
