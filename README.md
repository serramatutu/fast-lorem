# fast-lorem

Trying to generate Lorem Ipsum at maximum throughput.

## Benchmarking

Benchmarks are run using
```
./loremgenerator | pv > /dev/null
```

## What is valid Lorem Ipsum?

In order to keep a fair comparison between implementations, here I define some constraints for valid "Lorem Ipsum" text.

**Lorem Ipsum text** MUST
- start with `Lorem ipsum dolor sit amet`
- appear random
- be a concatenation of paragraphs, separated by `\n\n`

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
