def solution(cacheSize, cities):
    answer = 0
    cache = []
    
    if cacheSize == 0: 
        answer = 5 * len(cities)
        return answer
    for city in cities:
        c = city.lower()
        if c in cache:
            cache.pop(cache.index(c))
            cache.append(c)
            answer +=1
        else:
            if len(cache) < cacheSize:
                cache.append(c)
            else:
                cache.pop(0)
                cache.append(c)
            answer +=5
    return answer


input_cacheSize = 3
input_cities = ["Jeju", "Pangyo", "Seoul", "NewYork", "LA", "Jeju", "Pangyo", "Seoul", "NewYork", "LA"]
print(solution(input_cacheSize, input_cities))