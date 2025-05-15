
# c-cgi-framework

C言語でCGIアプリを作るための軽量フレームワーク。
動くものを見せて、業務ロジックに集中できる快適さを提供します。

## 特徴
- フレームワーク本体に共通処理を集約
- 業務ロジックは外部ファイル（hello.c など）で分離
- シンプルな構成・高速な動作
- GETパラメータ受信に対応
- HTMLフォームとCGI連携の最小構成

## ディレクトリ構成
```text
c-cgi-framework/
├── src/            # フレームワーク本体
├── include/        # ヘッダファイル群
├── examples/       # 業務ロジック例 (hello.c など)
├── public/         # 静的HTML (form.htmlなど)
├── Makefile        # ビルド＆デプロイ用
└── README.md
```

## 動作環境
- Apache HTTP Server
- UserDir モジュール有効
  - URL例：`http://localhost/~ユーザー名/`
  - CGI実行：`~/public_html/cgi-bin/`
  - 静的HTML：`~/public_html/`

### 参考構成
```text
~/public_html/
├── form.html
└── cgi-bin/
    └── hello.cgi
```

## 使い方

### ビルド
```bash
make
```

### デプロイ (CGI & HTML)
```bash
make deploy
```

### クリーン
```bash
make clean
```

### 動作確認
ブラウザで以下にアクセスします。
```
http://localhost/~ユーザー名/form.html
```
フォーム送信で hello.cgi が動作します。

## UserDir が使えない場合

Apache の `DocumentRoot` および `ScriptAlias` を設定してください。

例：`/var/www/` を使う場合
```apacheconf
DocumentRoot /var/www/html
ScriptAlias /cgi-bin/ /var/www/cgi-bin/
<Directory "/var/www/cgi-bin">
    Options +ExecCGI
    AddHandler cgi-script .cgi
</Directory>
```

### Makefile の deploy先変更
```makefile
PUBLIC_HTML = /var/www/html
CGI_BIN = /var/www/cgi-bin

deploy: $(TARGET)
	cp $(TARGET) $(CGI_BIN)/
	cp public/*.html $(PUBLIC_HTML)/
```

### 注意
- `/var/www/` 以下の操作は root 権限が必要な場合があります。
- `sudo` 付きで deploy するか、適切なパーミッション調整を行ってください。

## ライセンス
(c) 2024-2025 Shintaro Suzuki. All rights reserved.

※ 本プロジェクトは開発中です。公開時にMITライセンスを適用予定。
