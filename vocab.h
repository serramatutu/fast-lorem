#ifndef VOCAB_H
#define VOCAB_H

#define LOREM_VOCAB { \
    "lorem", "ipsum", "dolor", "sit", "amet", "consectetur", "adipisicing", "elit"\
    "exercitationem", "perferendis", "perspiciatis", "laborum", "eveniet", \
    "sunt", "iure", "nam", "nobis", "eum", "cum", "officiis", "excepturi", \
    "odio", "consectetur", "quasi", "aut", "quisquam", "vel", "eligendi", \
    "itaque", "non", "odit", "tempore", "quaerat", "dignissimos", \
    "facilis", "neque", "nihil", "expedita", "vitae", "vero", "ipsum", \
    "nisi", "animi", "cumque", "pariatur", "velit", "modi", "natus", \
    "iusto", "eaque", "sequi", "illo", "sed", "ex", "et", "voluptatibus", \
    "tempora", "veritatis", "ratione", "assumenda", "incidunt", "nostrum", \
    "placeat", "aliquid", "fuga", "provident", "praesentium", "rem", \
    "necessitatibus", "suscipit", "adipisci", "quidem", "possimus", \
    "voluptas", "debitis", "sint", "accusantium", "unde", "sapiente", \
    "voluptate", "qui", "aspernatur", "laudantium", "soluta", "amet", \
    "quo", "aliquam", "saepe", "culpa", "libero", "ipsa", "dicta", \
    "reiciendis", "nesciunt", "doloribus", "autem", "impedit", "minima", \
    "maiores", "repudiandae", "ipsam", "obcaecati", "ullam", "enim", \
    "totam", "delectus", "ducimus", "quis", "voluptates", "dolores", \
    "molestiae", "harum", "dolorem", "quia", "voluptatem", "molestias", \
    "magni", "distinctio", "omnis", "illum", "dolorum", "voluptatum", "ea", \
    "quas", "quam", "corporis", "quae", "blanditiis", "atque", "deserunt", \
    "laboriosam", "earum", "consequuntur", "hic", "cupiditate", \
    "quibusdam", "accusamus", "ut", "rerum", "error", "minus", "eius", \
    "ab", "ad", "nemo", "fugit", "officia", "at", "in", "id", "quos", \
    "reprehenderit", "numquam", "iste", "fugiat", "sit", "inventore", \
    "beatae", "repellendus", "magnam", "recusandae", "quod", "explicabo", \
    "doloremque", "aperiam", "consequatur", "asperiores", "commodi", \
    "optio", "dolor", "labore", "temporibus", "repellat", "veniam", \
    "architecto", "est", "esse", "mollitia", "nulla", "a", "similique", \
    "eos", "alias", "dolore", "tenetur", "deleniti", "porro", "facere", \
    "maxime", "corrupti" \
}

#define LOREM_MAX_WORD_LEN 14

#define LOREM_MAX_COMMAS 4

// 8 sentences of 40 words with 4 commas, 1 period and max word size, plus delimiter
#define LOREM_MAX_PARAGRAPH_SIZE (8 * 40 * (4 + 1) * LOREM_MAX_WORD_LEN + 2)

#endif