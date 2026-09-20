/*
题目描述：如果上一题中的程序读入了 256 个词，在 resize 之后容器的 capacity 可能是多少？如果读入了 512 个、1000 个或 1048 个词呢？
前提：reserve(1024)，初始 capacity≥1024；resize 只改变 size，不会减小 capacity。
解答

读入 256 个词push_back 结束 size=256，capacity ≥1024；resize 后 size=256+128=384。resize 不改变 capacity，capacity 仍为 1024。
读入 512 个词push_back 结束 size=512，capacity≥1024；resize 后 size=512+256=768。capacity 仍为 1024。
读入 1000 个词push_back 结束 size=1000，capacity≥1024；resize 后 size=1000+500=1500。此时新 size (1500) > 当前 capacity (1024)。resize 需要新增元素，会触发重新分配内存。capacity 会增长到大于等于 1500 的值（gcc 下翻倍策略，可能为 2048）。
读入 1048 个词push_back 的时候，size 到达 1025 就已经超过 reserve 预留的 1024，push_back 阶段就已经触发扩容，capacity 已经大于 1048。resize 后 size = 1048 + 524 = 1572。resize 需要 size 达到 1572，会再次扩容到≥1572（gcc 下 2048）。

说明：reserve (1024) 只是建议，标准不强制一定等于 1024；resize 扩容会分配更大内存，但不会缩小 capacity。
*/