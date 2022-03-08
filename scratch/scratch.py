

def quad_hash(k):
    hash_set = []
    for i in range(100):
        hash = ((2*k)+5) % 11
        quad = (i**2)
        key = (hash + quad) % 11
        hash_set.append(key)
        print(f'i: {i} Hash: {hash} Quad Hash: {quad} Key: {key}')
    print(f'All possible keys: {set(hash_set)}')


def quadratic_probe(size, elements):
    output = [0]*size
    for element in elements:
        i = 1
        hash = ((2*element)+5) % size
        while(output[hash] != 0):
            hash = ((((2*element)+5) % size) + i**2) % size
            i += 1
        output[hash] = element
        print(f'Index: {hash} Element: {element} i: {i-1}')
    print(f'{output}')
    return output


def linear_probe(size, elements):
    output = [0]*size
    for element in elements:
        i = 1
        count = 0
        hash = ((2*element)+5) % size
        print(f'Element: {element} Hash: {hash}')
        while(output[hash] != 0 and count < 50):
            hash = ((((2*element)+5) % size) + i) % size
            print(hash)
            i += 1
            count += 1
        output[hash] = element
        print(f'Index: {hash} Element: {element}')
    return output


def double_probe(size, elements):
    output = [0]*size
    for element in elements:
        i = 1
        count = 0
        hash = ((2*element)+5) % size
        while(output[hash] != 0 and count < 50):
            hash = ((((2*element)+5) % size) + i*(7-(element % 7))) % size
            print(hash)
            i += 1
            count += 1
        output[hash] = element
        print(f'Index: {hash} Element: {element} i: {i-1}')
    return output


def main():
    size = 11
    elements = [12, 44, 13, 88, 23, 94, 11, 39, 20, 16, 5]
    print(double_probe(size, elements))


if __name__ == '__main__':
    main()
