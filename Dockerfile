FROM ruby:2.6.4-slim

RUN apt-get update && \
    apt-get install -y --no-install-recommends build-essential bash bison ca-certificates openssl git

ENV WORKSPACE=/work
RUN mkdir -p $WORKSPACE
WORKDIR $WORKSPACE

CMD [ "bash" ]
