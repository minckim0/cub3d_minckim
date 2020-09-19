# cub3D
miniLibX로 구현하는 첫 RayCaster

---
## 목차
1. 서문
2. 목표
3. 일반 수칙
4. 필수과제 - cub3D
5. 보너스 과제
6. 예시

---
## 제1 장 서문
"엄청나게" 유명한 존 카맥(John Carmack)과 존 로메로(John Romero)의 이드소프트웨어(Id Software)가 개발하고, 1992년 어포지 소프트웨어(Apogee Software)가 유통한 울펜스타인 3D(Wolfenstein 3D)는 비디오 게임 역사상 최초의 "진정한 일인칭 슈터(Fisrt Person Shooter)" 입니다.

울펜스타인 3D는 둠(Doom, 이드 소프트웨어, 1993), 둠II(Doom II, 이드 소프트웨어, 1994), 듀크 누켐(Duke Nukem, 3D Realm, 1996), 퀘이크(Quake, 이드 소프트웨어, 1996) 같은 게임들의 조상격이고, 비디오 게임계의 영원한 이정표입니다.

이제 여러분이 역사를 이어갈 차례입니다...

---
## 제2 장 목표
이 프로젝트의 목표는 첫 해의 목표와 비슷합니다. 엄격함, C 사용, 기본 알고리즘 사용, 정보 검색 등.

그래픽 디자인 프로젝트로서, cub3D는 다음 영역에서의 기술을 향상시켜줄 것입니다. 창, 색, 사건, 모양 채우기 등.

결론적으로 cub3D는 구체적인 내용을 이해하지 않고도 수학의 실제적인 응용을 탐구 할 수있는 놀라운 놀이터입니다

인터넷에서 구할 수 있는 수많은 문서의 도움을 받아서 여러분은 수학을 우아하고 효과적인 알고리즘을 만드는 도구로 사용할 수 있을 것입니다.

이 프로젝트를 시작하기 전에 원작 게임을 테스트 해보기를 권합니다.
http://users.atw.hu/wolf3d/

---
## 제3 장 일반 수칙
- 여러분의 프로젝트는 반드시 Norm을 준수해야 합니다. 보너스 파일이나 함수가 있다면 그것들도 Norm체크에 포함되고, 내부적으로 norm에러가 발생하면 0점을 받을 것입니다.
- 여러분의 함수는 정의되지 않은 동작으로 예상치 못하게 종료(세그먼테이션 오류, 버스에러, 이중 해제)되어서는 안 됩니다. 만약 그런 일이 발생한다면 여러분의 프로젝트는 함수 없음으로 간주되고 평가에서 0점을 받을 것입니다.
- 모든 힙에 할당된 메모리는 반드시 적절하게 해제되어야 합니다. 어떠한 누수도 용납되지 않습니다.
- 프로젝트에 필요하다면, 여러분의 소스 파일을 필요한 결과물로 -Wall -Wextra -Werror 플래그를 써서 컴파일하는 Makefile을 반드시 제출해야 하고, 절대로 relink되어서는 안 됩니다.
- 여러분의 Makefile은 최소한 $(NAME), all, clean, fclean, re 규칙은 포함해야 합니다.
- 여러분의 프로젝트에 보너스를 제출하려면, Makefile에 bonus 규칙을 포함시켜야 하고, 프로젝트의 주요 파트에서는 금지되었던 다양한 헤더, 라이브러리나 함수를 추가할 것입니다.
- 보너스는 반드시 _bonus.{c/h}라는 다른 파일이어야 합니다. 필수 파트와 보너스 파트 평가는 따로 될 것입니다.
- 여러분의 프로젝트가 libft 사용을 허락한다면, 여러분은 반드시 libft 폴더에 그 소스를 복사하고 관련된 Makefile을 두어야 합니다. 여러분의 프로젝트의 Makefile이 libft의 Makefile을 이용해서 라이브러리를 컴파일 해야 하고, 그런 다음 프로젝트를 컴파일 합니다.
- 제출되지 않고 평가받지도 않겠지만, 테스트 프로그램을 만들어볼 것을 권합니다. 동료평가를 수월하게 해 줄 것입니다. 여러분은 이런 테스트가 특히 여러분의 디펜스에 유용하다는 것을 알게 될 것입니다. 게다가 디펜스 하는 동안 여러분은 테스트를 편하게 써도 되고, 동료를 평가해 줄 때에도 마찬가지 입니다.
- 여러분에게 할당된 깃 저장소에 제출하세요. 깃 저장소에 있는 작업물만 평가될 것입니다. Deepthought이 여러분의 과제 평가에 할당되면, 여러분의 동표평가 후에 Deepthought가 평가를 마칠 것입니다. Deepthought가 평가하는 도중에 어느 부분에서든 오류가 발생한다면 평가는 중단됩니다.

---
## 제4 장 필수 파트 - cub3D
- 프로그램 이름 : cub3D
- 제출 파일 : 모든 파일
- Makefile : all, clean, fclean, re, bonus
- 인자 : a map in format *.cub
- 외부 함수 :
	- open, close, read, write, malloc, free, perror, strerror, exit
	- math 라이브러리의 모든 함수(-lm man 3 math)
	- MinilibX의 모든 함수
- Libft 허용 : yes
- 기술 : 여러분은 일인칭 원근법으로 본 미로 내부의 "현실적인" 3D 그래픽 연출을 만들어내야 합니다. 이런 연출은 전에 Ray-casting 이론으로 불리던 것을 이용해서 만들어 내야 합니다.

- 제한사항은 다음과 같습니다:
	- 여러분은 반드시 miniLibX를 사용해야 합니다. 운영체제에서도 사용가능하고 해당 소스에서도 사용가능한 버전입니다. 소스를 사용하기로 선택한 경우, 일반 지시 사항 파트에서 작성된 것과 동일한 규칙을 libft에 적용해야합니다.
	- 창 조절은 부드럽게 되어야 합니다. 다른 창으로 변경하거나 최소화 할 때 등.
	- 동서남북 방향에 따라 다른 벽 텍스처(선택은 여러분의 몫)를 보여 주십시오.
	- 여러분의 프로그램은 벽 대신에 아이템을 보여줄 수 있어야 합니다.
	- 여러분의 프로그램은 바닥과 천장을 각각 다른 두 색으로 보여주어야 합니다.
	- Deepthought가 언젠가 프로젝트를 평가하는 경우, 프로그램은 두 번째 인수가 "–-save"일 때 첫 렌더링 된 이미지를 bmp 형식으로 저장해야합니다.
	- 두 번째 인수가 없는 경우, 프로그램은 창에 있는 이미지를 보여주고, 다음의 규칙을 따릅니다.
		- 왼쪽 오른쪽 방향키는 미로의 왼쪽과 오른쪽을 볼 수 있게 합니다.
		- WASD 키는 미로 안에서 보는 쪽으로 움직이게 합니다.
		- ESC키를 누르면 창을 닫고 프로그램을 완전히 종료합니다.
		- 창틀의 빨간 십자를 누르면 창을 닫고 프로그램을 완전히 종료합니다.
		- 지도에서 선언된 스크린 크기가 디스플레이 해상도보다 크다면 창의 사이즈는 현재 디스플레이 해상도에 따라 설정될 것입니다.
		- miniLibX의 이미지를 사용하는 것을 강력하게 권합니다.
	- 여러분의 프로그램은 .cub확장자로 된 scene description 파일을 인수로 받아야 합니다.
		- 지도는 딱 4개의 가능한 문자로 구성되어야 합니다. "0"은 빈 공간, "1"은 벽, "2"는 아이템, NSEW는 플레이어의 시작점과 스폰 지점입니다.
		이건 간단한 유효 지도입니다.

				111111
				100101
				102001
				102001
				1100N1
				111111

		- 지도는 벽으로 둘러싸여 닫혀야 하고, 그렇지 않으면 프로그램은 에러를 반환해야 합니다.
		- 지도의 콘텐츠를 제외하고, 각 요소마다 한 줄 이상의 분리되어있어야 합니다.
		- 맨 끝에 나와야 하는 지도의 콘텐츠를 제외하고는 각 요소마다 어느 순서로든 있을 수 있습니다.
		- 지도를 제외하고, 각 요소의 정보는 한개 이상의 공백으로 떨어져 있을 수 있습니다.
		- 지도는 파일에 보이는대로 해석되어야 합니다. 빈 공간은 지도의 유효한 부분이고, 그건 여러분이 다루기 나름입니다. 지도의 규칙을 따르기만 한다면 어떠한 종류의 지도라도 해석할 수 있어야 합니다.
		- 지도를 제외한 각 요소의 첫 번째 정보는 유형 구분자(한 개나 두개의 문자로 구성됨)이고, 그 뒤로 각 오브젝트에 따른 특정 정보가 엄격한 순서로 뒤따르는데 이런 식입니다.
			- 해상도:

					R 1920 1080
				- 구분자 : R
				- x render size
				- y render size
			- 북쪽 텍스처:

					NO ./path_to_the_north_texture
				- 구분자: NO
				- 북쪽 텍스처의 경로
			- 남쪽 텍스처:

					SO ./path_to_the_south_texture
				- 구분자 : SO
				- 남쪽 텍스처의 경로
			- 서쪽 텍스처:

					WO ./path_to_the_west_texture
				- 구분자 : WE
				- 남쪽 텍스처의 경로
			- 동쪽 텍스처:

					EO ./path_to_the_east_texture
				- 구분자 : SA
				- 남쪽 텍스처의 경로
			- 스프라이트 텍스처:

					S ./path_to_the_sprite_texture
				- 구분자 : S
				- 스프라이트 텍스처의 경로
				- (역자주: [스프라이트가 무엇인가. 나무위키](https://namu.wiki/w/%EC%8A%A4%ED%94%84%EB%9D%BC%EC%9D%B4%ED%8A%B8#s-3))
			- 바닥 색:

					F 200,100,0
				- 구분자: F
				- R,G,B 색. 범위[0,255]: 0,255,255
			- 천장 색:

					C 223, 30, 0
				- 구분자: C
				- R,G,B 색. 범위[0,255]: 0,255,255

		- 필수 요소만 최소한으로 갖춘 .cub 씬 예시:

				R 1920 1080
				NO ./path_to_the_north_texture
				SO ./path_to_the_south_texture
				WE ./path_to_the_west_texture
				EA ./path_to_the_east_texture
				S ./path_to_the_sprite_texture
				F 220,100,0
				C 225,30,0
				        1111111111111111111111111
				        1000000000110000000000001
				        1011000001110000002000001
				        1001000000000000000000001
				111111111011000001110000000000001
				100000000011000001110111111111111
				11110111111111011100000010001
				11110111111111011101010010001
				11000000110101011100000010001
				10002000000000001100000010001
				10000000000000001101010010001
				11000001110101011111011110N0111
				11110111 1110101 101111010001
				11111111 1111111 111111111111

		- 파일에 조금이라도 잘못 설정된 것이 있다면 프로그램은 적절히 종료되어야 하고 "Error\n"를 반환하고 여러분이 택한 명시적인 메시지가 뒤따라야 합니다.

---
## 제5 장 보너스 파트
> 보너스는 필수 파트가 완벽할 때에만 평가될 것입니다. 완벽하다는 건 완전하고, 실패해서는 안 되고, 당연히 오용과 같은 잡스러운 실수도 없음을 뜻합니다. 기본적으로 여러분의 필수파트가 평가과정에서 모든 점수를 따내지 못하면, 여러분의 보너스는 완전히 무시될 것입니다.

### 보너스 리스트:
- 벽 충돌ㅋ
- 하늘 박스
- 바닥과 벽 텍스처(또는 둘 중 하나)
- HUD
- 위아래 볼 수 있게 하기
- 뛰거나 웅크리기
- 거리에 따른 그림자 효과
- 라이프바
- 미로에 더 많은 아이템
- 물체 충돌
- 오브젝트 줍기나 함정으로 점수나 생명 얻거나 잃기
- 문이 열리거나 닫히게 하기
- 비밀의 문
- 총 쏘는 애니메이션 또는 움직이는 스프라이트
- 몇몇 레벨
- 소리와 음악
- 마우스로 시점 변경
- 무기, 해치울 악당

> 모든 보너스 포인트를 얻으려면 이 것들 중 14개를 깨야 하고, 그러므로 현명하게 선택하되 시간을 낭비하지 않게 조심하십시오.

> 여러분은 다른 함수들의 사용이 정의되어 있기만 하다면 보너스 파트를 마치기 위해 그것들을 쓸 수 있도록 허가되었습니다. 또한 여러분은 여러분의 필요에 따라 장면 파일의 포멧을 바꾸는 것이 허가되어 있습니다. 부디 똑똑하게 하시길!