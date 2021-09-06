import discord
from discord.ext.commands import Bot
intents = discord.Intents.default()
bot = Bot(command_prefix='!', intents=intents)


@bot.event
async def on_ready():
    print(f'{bot.user} 에 로그인하였습니다!')


@bot.event
# async def on_message(message):
#     if message.content.startswith("학폭"):
#         author = message.guild.get_member(882896742461374495)
#         await bot.get_user(message.author.id).send('test')
#         #await bot.author.send("당신의 아이를 납치했다")
# async def on_message(message):
#     if message.content.startswith("DM"):
#         author = message.guild.get_member(int(message.content[4:22]))
#         msg = message.content[23:]
#         await author.send(msg)
@bot.command(pass_context=True)
async def dm(ctx):
    user=await bot.get_user_info(490837616573415425)
    await bot.send_message(user, "Your message goes here")
    # This works ^
@bot.command(name="DM보내기", pass_context=True)
async def send_dm(ctx, user_name: discord.Member):
    channel = await user_name.create_dm()
    await channel.send("Python Bot에 의해 출력됨.")
bot.run('ODgyODk2NzQyNDYxMzc0NDk1.YTCDqg.IkLeuHLnm3ZFc5AVoD_USIBu7lY')
