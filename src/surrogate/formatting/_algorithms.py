pacc_headers_ = ["iter", "s_train", "n_s_test < epsilon", "n_s_test",
                 "Pr(|fsm(x)-f(x)| <= epsilon)"]
pacc_header_len = list(map(lambda x: len(x) + 2, pacc_headers_))
pacc_headers = [("{:^" + str(len(h) + 2) + "}").format(h) for h in
                pacc_headers_]


def print_pacc_header():
    print('+'.join([""] + ["-" * len_h for len_h in pacc_header_len] + [""]))
    print('|'.join([""] + pacc_headers + [""]))
    print('+'.join([""] + ["-" * len_h for len_h in pacc_header_len] + [""]))


def print_pacc_iteration(iteration, s_num, evaluation_log):
    cols = [iteration, s_num,
            evaluation_log.n_passing,
            evaluation_log.n_samples,
            round(evaluation_log.statistic, 3)]

    print('|'.join(
        [""] + [("{:^" + str(len_h) + "}").format(col) for len_h, col
                in zip(pacc_header_len, cols)] + [""]))
