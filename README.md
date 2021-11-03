# fast-lorem

Trying to generate Lorem Ipsum at maximum throughput.

## What is valid Lorem Ipsum?

In order to keep a fair comparison between implementations, here I define some constraints for valid "Lorem Ipsum" text.

**Lorem Ipsum text** MUST
- seem random and non-repetitive
- be a concatenation of paragraphs, separated by `\n\n`
- only contain valid words/separators (null bytes in the output would increase throughput, so that's not valid)

**Paragraphs** MUST
- randomly contain between 3 to 8 sentences
- be a concatenation of sentences, separated by ` ` (spaces)

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

Programs are compiled with GCC 11.2 with level 3 optimization enabled (`-O3`).

|Generator          | Throughput |
|-------------------|------------|
|`naive.c`          |236 MiB/s   |
|`parallel_write.c` |3.74 GiB/s  |

**TODO:** Graph throughput over time.