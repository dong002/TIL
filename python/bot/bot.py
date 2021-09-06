import discord 
from discord.ext.commands import Bot
#embed = discord.Embed(title="!FBI WARNING¡", description="당신의 학생이 학교폭력상황에 노출되어있습니다", color=0x62c1cc) # Embed의 기본 틀(색상, 메인 제목, 설명)을 잡아줍니다
#embed.set_footer(text="하단 설명") # 하단에 들어가는 조그마한 설명을 잡아줍니다
intents=discord.Intents.default()
bot = Bot(command_prefix='!', intents=intents)
mum=0
@bot.event
async def on_ready():
    print(f'{bot.user} 에 로그인하였습니다!')

@bot.command()
async def ping(ctx):
    await ctx.send('pong!')


@bot.command()
async def 멈춰(ctx):
    await ctx.reply('멈춰!!')

# if message.content=="학폭":
#     if message.author.dm.channel:
#         await message.author.dm_channel.send("ㅇㄴㅇㄴ")
#         #await message.channel.send(embed=embed) # embed를 포함 한 채로 메시지를 전송합니다.
#         #await message.channel.send("", embed=embed) # embed와 메시지를 함께 보내고 싶으시면 이렇게 사용하시면 됩니다.
#     elif message.author.dm_channel is None:
#         channel = await message.author.create_dm()
#         await channel.send("ㅇㄴㅇㄴ")

#출처: https://code-200.tistory.com/62 [CODE 200]
@bot.command()
async def 학폭(ctx):
    try:
        bot.get_user(ctx.author.id).send("텍스트")
    except discord.errors.Forbidden:
        await ctx.send(f"{ctx.message.author.mention}님 서버 이름 클릭 - 개인정보 보호 설정 - 서버 멤버가 보내는 개인 메시지 허용해주세요.")



async def 따라해(ctx,*,content):

    await ctx.reply(content)

    

@bot.command()
async def 반복해(ctx,i,*,content):
    j=0
    mum=0
    for j in range(int(i)):
        await ctx.reply(content)
        if mum==1:
            break

    
bot.run('ODgyODk2NzQyNDYxMzc0NDk1.YTCDqg.IkLeuHLnm3ZFc5AVoD_USIBu7lY')