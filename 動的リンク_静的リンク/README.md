# 概要
標準出力(std::cout)と標準エラー出力(std::cerr)をリダイレクトの観点で学びたい


# 流れ
1. ソースコードcpp(lib_hello.cpp) から オブジェクトファイルo を作成する
   1. g++ -c hello.cpp
   2. hello.o が作成される
2. オブジェクトファイルo から 共有ライブラリを作成する 
   1. g++ -shared -o lib_hello.dll hello.o
   2. lib_hello.dll が作成される
3. ソースコードcpp(hello.cpp) のヘッダーh(hello.h)
4. コンパイルするときに、ダイナミックリンクライブラリ(lib_hello.dll)をリンク
   1. g++ -I./ -L./ -o main.exe main.cpp -llib_hello
   2. main.exe が作成できた
5. main.exe を実行する
   1. 実行結果
      1. std_cerr
      2. std_cerr
6. テスト
   1. リダイレクト( > )
      1. 実行コマンド
         1. $ .\main.exe > main_exe.log
      2. 実行結果
         1. std_cerr
      3. 詳細
         1. main_exe.log が生成されて、std_cout の文字列が書き込まれていた
         2. コマンドラインには、 std_cerr が出力されていた
   2. リダイレクト( 1> )
      1. 実行コマンド
         1. $ .\main.exe > main_exe.log
      2. 実行結果
         1. std_cerr
      3. 詳細
         1. main_exe.log が生成されて、std_cout の文字列が書き込まれていた
         2. コマンドラインには、 std_cerr が出力されていた
         3. 1> の 1 は、ファイルディスクリプタの標準出力を示す
   3. リダイレクト( 1> )
      1. 実行コマンド
         1. $ .\main.exe 1> main_exe.log
      2. 実行結果
         1. std_cerr
      3. 詳細
         1. main_exe.log が生成されて、std_cout の文字列が書き込まれていた
         2. コマンドラインには、 std_cerr が出力されていた
         3. 1> の 1 は、ファイルディスクリプタの標準出力を示す
   4. リダイレクト( 2> )
      1. 実行コマンド
         1. $ .\main.exe 2> main_exe.log
      2. 実行結果
         1. std_cout
      3. 詳細
         1. main_exe.log が生成されて、std_cerrに関するエラー の文字列が書き込まれていた
         2. コマンドラインには、 std_cout が出力されていた
         3. 2> の 2 は、ファイルディスクリプタの標準エラー出力を示す
   5. リダイレクト( 2>&1 > )
      1. 実行コマンド
         1. $ .\main.exe 2>&1 > main_exe.log
      2. 実行結果
         1. なし
      3. 詳細
         1. main_exe.log が生成されて、下記の文字列が書き込まれていた
            std_cout
            .\main.exe : std_cerr
            発生場所 行:1 文字:1
            + .\main.exe 2>&1 > main_exe.log
            + ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
               + CategoryInfo          : NotSpecified: (std_cerr:String) [], RemoteException
               + FullyQualifiedErrorId : NativeCommandError 
         2. コマンドラインには、 出力なし
         3. 2>&1 >  で、標準出力 と 標準エラー出力 を書き込む
         4. 2(標準エラー出力) と 1(標準出力) を一緒に書き込むということ？


# [参考] Bashのリダイレクト(`>`と`>&`)とパイプ等についてのまとめ
https://qiita.com/task4233/items/1f5ba68e8fed430f6f9f#-test-21--outtxt


# [参考] 【bash】リダイレクトとパイプを理解する（１）
https://horus531.hatenadiary.org/entry/20101230/1295162296

≪記述例≫
$ ls 2>&1  ･･･  lsコマンドの標準エラー出力を標準出力と同じ出力先にリダイレクトする。
$ ls 1>&2  ･･･  lsコマンドの標準出力を標準エラー出力と同じ出力先にリダイレクトする。
