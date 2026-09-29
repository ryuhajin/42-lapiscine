# LaPiscine · 42 Seoul

> 42 Seoul C Piscine(선발 과정)의 Shell / C 모듈, Rush, 최종 과제 BSQ 모음

## 개요
Shell 기초부터 C의 포인터·문자열·재귀·동적 할당·Makefile까지 단계별로 익히는 과정이다.
각 모듈은 `exNN/` 폴더 단위의 독립된 연습 문제로 이루어져 있으며, 대부분 함수 하나만 제출하는 형태라
저장소 전체를 한 번에 빌드하는 명령은 없다. Rush와 BSQ는 팀 과제다.

## 모듈 구성
| 폴더 | 내용 |
|---|---|
| `Shell00` | 파일 권한과 `tar` 아카이브, `ls` 옵션(`midLS`), git 명령(`git_commit.sh`, `git_ignore.sh`), `find`로 임시 파일 정리(`clean`), `file` 매직 규칙(`ft_magic`) |
| `Shell01` | 파이프라인 스크립트: `id`, `find`, `wc`, `ifconfig`, `awk`, `sed`, `rev`, `bc`로 진법 변환(`add_chelou.sh`) |
| `C00` | `write`만으로 출력하기: `ft_putchar`, `ft_putnbr`, 조합 출력 `ft_print_comb` / `ft_print_combn` |
| `C01` | 포인터 기초: `ft_ft`, `ft_ultimate_ft`, `ft_swap`, `ft_div_mod`, 배열 뒤집기·정렬 |
| `C02` | 문자열 복사와 판별·변환: `ft_strcpy`, `ft_strlcpy`, `ft_str_is_*`, `ft_strcapitalize`, `ft_print_memory` |
| `C03` | 문자열 비교·연결·검색: `ft_strcmp`, `ft_strncat`, `ft_strstr`, `ft_strlcat` |
| `C04` | 숫자↔문자열 변환과 진법: `ft_atoi`, `ft_putnbr_base`, `ft_atoi_base` |
| `C05` | 반복과 재귀: 팩토리얼, 거듭제곱, 피보나치, 제곱근, 소수, `ft_ten_queens_puzzle` |
| `C06` | `argc` / `argv` 다루기: 프로그램 이름, 인자 출력·역순·정렬 |
| `C07` | 동적 할당: `ft_strdup`, `ft_range`, `ft_strjoin`, `ft_convert_base`, `ft_split` |
| `C08` | 헤더와 매크로, 구조체: `ft.h`, `ft_boolean.h`, `ft_abs.h`, `ft_point.h`, `t_stock_str` |
| `C09` | 정적 라이브러리와 Makefile: `libft_creator.sh`, `libft.a`용 `Makefile`, `ft_split` |
| `Rush00` | 가로·세로 크기를 받아 문자로 사각형 테두리 출력 (`rush00.c`, `rush03.c`) |
| `rush01` | 4x4 스카이스크래퍼 퍼즐: 16개 단서 입력 → 24개 순열 행을 재귀로 배치하며 조건 검사 |
| `Rush02` | 숫자를 영어로 읽는 과제. 저장소에는 `numbers.dict`, 사전 읽기 테스트(`open.c`), 연결 리스트 유틸(`t_list.c`)만 포함 |
| `BSQ` | 최종 과제: 가장 큰 정사각형 찾기 (아래 참고) |

## BSQ (Biggest Square)
장애물이 있는 지도에서 장애물을 피해 놓을 수 있는 가장 큰 정사각형을 찾아 채워 출력한다.

- 첫 줄(`9.ox` 형태)에서 줄 수와 빈칸·장애물·채움 문자를 파싱 (`get_map_info`)
- `check_map`으로 줄 수, 모든 행의 길이, 문자 구성, 세 문자의 중복 여부를 검증하고 실패 시 `map error` 출력
- 지도를 테두리가 있는 `int` 2차원 배열로 바꾼 뒤(`allocate_map`, `init`, `generate`) DP로 계산:
  `map[i][j] = min(좌상, 상, 좌) + 1` (`recurrence_relation`)
- 가장 큰 값의 위치와 크기를 `t_square`에 기록하고 `print_map`에서 해당 영역을 채움 문자로 출력
- 인자가 없으면 표준 입력, 있으면 파일 여러 개를 순서대로 처리

```bash
cd BSQ
make
./bsq map1.txt map2.txt   # 파일 입력
./bsq < map.txt           # 표준 입력
```

입력 예시:
```
5.ox
.....
..o..
.....
o....
.....
```

## 구조
```
LaPiscine/
├── Shell00/ Shell01/     # exNN/ 단위 쉘 과제
├── C00/ ... C09/         # exNN/ 단위 C 과제
├── Rush00/ rush01/ Rush02/
└── BSQ/
    ├── Makefile
    ├── includes/         # check.h, map.h, square.h ...
    └── srcs/             # main.c, check.c, find_square.c, map_manager.c, printer.c ...
```

42 Seoul 공통 과정 과제.
