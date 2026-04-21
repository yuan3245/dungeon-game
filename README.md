# Dungeon Game

一個以 C++ 撰寫的文字型探險遊戲 (Text-based Dungeon Adventure Game)，作為物件導向程式設計課程的期末專案。玩家需要在多個房間之間移動、與 NPC 互動、與怪物戰鬥，最終擊敗最終 Boss 才能通關。

## 專案特色

- 以物件導向 (OOP) 的方式設計，運用inheritance和virtual function等手法來組織遊戲中的各種實體及其功能
- 使用 `GameCharacter` 作為基底類別，`Player`、`Monster`、`NPC` 分別繼承自它
- 使用 `Object` 作為道具類物件的基底類別，`Item` 繼承自它
- 透過 `Room` 類別組成地圖，房間之間以指標互相連結 (上下左右)，形成可探索的關卡

## 類別架構

| 類別 | 說明 |
| --- | --- |
| `Dungeon` | 遊戲主控制器，負責遊戲初始化、玩家移動、動作選擇與遊戲流程 |
| `GameCharacter` | 所有角色的基底類別，定義 HP、攻擊力等共通屬性 |
| `Player` | 玩家，可移動、攻擊、使用道具 |
| `Monster` | 怪物，可被玩家攻擊或反擊玩家 |
| `NPC` | 非玩家角色，可提供對話或交易 |
| `Room` | 房間，儲存內部的怪物 / NPC，並連結到相鄰房間 |
| `Object` / `Item` | 遊戲中的物件與道具 |

## 檔案結構

```
.
├── main.cpp              程式進入點
├── Dungeon.{h,cpp}       遊戲主流程
├── GameCharacter.{h,cpp} 角色類別
├── Player.{h,cpp}        玩家類別
├── Monster.{h,cpp}       怪物類別
├── NPC.{h,cpp}           NPC 類別
├── Room.{h,cpp}          房間類別
├── Object.{h,cpp}        物件基底類別
├── Item.{h,cpp}          道具類別
├── Record.h              紀錄相關定義
└── report.pdf            專案報告
```

## 如何編譯與執行

使用 `g++` 一次編譯所有原始碼：

```bash
g++ -std=c++11 -o dungeon *.cpp
./dungeon        # Linux / macOS
dungeon.exe      # Windows
```

## 技術重點

- C++11
- 物件導向：繼承、多型、虛擬函式、封裝(public, private)
- 指標的應用 (房間之間以指標互相連結)
- 基本的遊戲迴圈及邏輯設計

## 專案報告

更詳細的設計說明請參考 [report.pdf](./report.pdf)。