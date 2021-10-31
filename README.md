# fast-lorem

Trying to generate Lorem Ipsum at maximum throughput.

## What is valid Lorem Ipsum?

In order to keep a fair comparison between implementations, here I define some constraints for valid "Lorem Ipsum" text.

**Lorem Ipsum text** MUST
- start with `Lorem ipsum dolor sit amet`
- appear random
- be a concatenation of paragraphs, separated by `\n\n`
- only contain valid words/separators (null bytes in the output would increase throughput, so that's not valid)

**Paragraphs** MUST
- randomly contain between 3 to 8 sentences

**Sentences** MUST
- start with a capital letter
- end with a period
- have random length between 3 and 40 words
- randomly contain 0 to 1 comma if length is in `(3, 6]`
- randomly contain 0 to 2 commas if length is in `(6, 12]`
- randomly contain 1 to 4 commas otherwise

**Words** MUST
- be defined in the Lorem Ipsum vocabulary (`vocab.h`)

## Performance benchmarks

Performance is measured using `./loremgenerator | pv > /dev/null` on my computer:
- **Processor:** Intel® Core™ i7-8565U CPU @ 1.80GHz (8 threads)
- **Memory:** 16GB
- **OS:** Ubuntu 20.04.3 LTS
- **Kernel:** Linux 5.4.0-89-generic x86_64

|Generator | Throughput|
|----------|-----------|
|`naive.c` |228 MiB/s  |

**TODO:** Graph throughput over time.