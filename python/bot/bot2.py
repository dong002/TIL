import discord
#from discord.ext.commands import client
embed = discord.Embed(title="!FBI WARNING¡", description="당신의 학생이 학교폭력상황에 노출되어있습니다", color=0x62c1cc) # Embed의 기본 틀(색상, 메인 제목, 설명)을 잡아줍니다
embed.set_footer(text="히히갓지다ㅣㄷㅈㅇ") # 하단에 들어가는 조그마한 설명을 잡아줍니다
embed.set_image(url="https://cdn.discordapp.com/attachments/852132409125109792/883212442371510272/3ef8dc45545b30b0.PNG")
class MyClient(discord.Client):
    async def on_ready(self):
        print("로긴!", self.user)
    async def on_message(self, message):
        if message.author == self.user:
            return
        if message.content == "학폭":
            # author = await client.get_user(490837616573415425).create_dm()
            # await author.send("on_ready가 호출되었습니다.")
            if message.author.dm_channel:
                await message.author.dm_channel.send("대신 귀여운 라이덴짱을 드리겠읍니다",embed=embed)
            elif message.author.dm_channel is None:
                channel = await message.author.create_dm()
                await channel.send("대신 귀여운 라이덴짱을 드리겠읍니다",embed=embed)
Client = MyClient()
Client.run('ODgyODk2NzQyNDYxMzc0NDk1.YTCDqg.IkLeuHLnm3ZFc5AVoD_USIBu7lY')