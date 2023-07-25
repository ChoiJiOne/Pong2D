# Pong2D
- 2D 퐁 게임의 *v0.0* 버전입니다.
<br><br>


## 사전 준비

이 프로젝트를 빌드 및 유지 개발을 진행하기 위해서는 다음 요소가 필요합니다.
- [Visual Studio 2019 혹은 그 이상](https://visualstudio.microsoft.com/ko/)
- [git](https://git-scm.com/)
<br><br>


## 저장소 복제본 얻기

`CMD` 에서 다음과 같이 수행하시면 *v0.0*의 저장소 복제본을 얻을 수 있습니다.
```
> git clone https://github.com/ChoiJiOne/Pong2D --single-branch -b v0.0
```
<br><br>


## Visual Studio Solution 생성

`CMD` 에서 다음과 같이 수행하시면 Visual Studio Solution를 생성할 수 있습니다.
```
> GenerateProjectFiles.bat
```
<br><br>


## 플레이

`RunGame.bat`를 클릭해서 실행하면, 시작화면에서 `START`와 `QUIT` 버튼을 클릭할 수 있습니다. `START`를 클릭하면 게임을 시작하고 `QUIT` 버튼을 클릭하면 게임을 종료하게 되는데, 왼쪽 플레이어는 `Q`와 `A`, 오른쪽 플레이어는 `UP`, `DOWN` 방향키로 조정할 수 있고, 먼저 5점을 획득하면 승리하게 됩니다. 이때, `ESC`키를 누르면 게임을 일시 중지시킬 수 있습니다.
